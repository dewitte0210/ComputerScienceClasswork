import cv2
import numpy as np

peppers = cv2.imread("standard_test_images/peppers_color.tif", cv2.IMREAD_COLOR)
print(peppers.shape)

# 1 DISPLAY PEPPERS AT HALF SIZE
peppersHalf = peppers[::2, ::2]

# 1A, SHEAR MULTIPLE COPIES TO MAKE A BOX
height, width = peppersHalf.shape[:2]
peppersNeg = 255 - peppersHalf[:, 256::-1]
finalCanvas = np.zeros(((2*height + width - 1), width * 2, 3), dtype=np.uint8)
print(width)

#places the negative images in the canvas. the flipping is there to get the shear from bottom up on the top left image
for col in range(width):
    finalCanvas[col:col + width, width + col] = peppersNeg[:, col]  
    finalCanvas = finalCanvas[:, width*2::-1]
    finalCanvas[col:col + width, width + col] = peppersNeg[:, -col]  
    finalCanvas = finalCanvas[:, width*2::-1]
#place the normal images on the bottom.
for col in range(width):
    finalCanvas[height + col:height + width + col, col] = peppersHalf[:, col]  
    finalCanvas = finalCanvas[:, width * 2::-1]
    finalCanvas[height + col:height + width + col, col] = peppersHalf[:, -col]  
    finalCanvas = finalCanvas[:, width*2::-1]

cv2.imshow("BEHOLD...THE BOX", finalCanvas)
cv2.imwrite("Peppers_Box.jpg", finalCanvas)

# 2 GAMMA CORRECTION OF 1.5
gammaPeppers = ((peppers.astype('float32') / 255) ** (1 / 1.5))
gammaPeppers *= 255
# cv2.imshow("Gamma Corrected Peppers", gammaPeppers.astype('uint8'))
cv2.imwrite("Peppers_Gamma.tif", gammaPeppers.astype('uint8'))

# 3 CREATE A 50% WEIGHTED AVERAGE OF TWO PICTURES
img1 = cv2.imread("standard_test_images/peppers_color.tif")
img2 = cv2.imread("standard_test_images/mandril_color.tif")
img3 = img1 // 2 + img2 // 2
redBorder = np.zeros((532, 532, 3), dtype=np.uint8)
redBorder[:, :, 2] = 255
redBorder[10:-10, 10:-10] = img3
cv2.imshow("Average", redBorder)
cv2.imwrite("Mandril_Border.tif", redBorder)

# 4 CREATE A GRAYSCALE IMAGE USING THE AVERAGE INTENSITY OF THE COLOR CHANNELS
grayPeppers = peppers
grayPeppers = grayPeppers / 255.0
grayPeppers = (grayPeppers[:, :, 0] + grayPeppers[:, :, 1] + grayPeppers[:, :, 2]) / 3
grayPeppers = grayPeppers * 255
# cv2.imshow("Gray Peppers", np.uint8(grayPeppers))
cv2.imwrite("Peppers_Gray.tif", np.uint8(grayPeppers))

# Display images
cv2.imshow("Peppers", peppers)
cv2.waitKey(0)
cv2.destroyAllWindows()