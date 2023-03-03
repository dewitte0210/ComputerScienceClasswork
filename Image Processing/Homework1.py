import cv2
import numpy as np

peppers = cv2.imread("standard_test_images/standard_test_images/peppers_color.tif", cv2.IMREAD_COLOR)
print(peppers.shape)

# 1 Display peppers at half size
peppersHalf = peppers[::2, ::2]
##cv2.imshow("Peppers at Half Size", peppersHalf)
cv2.imwrite("Peppers_Half.tif", peppersHalf)

# Multiple copies of the sheared Image
height, width = peppersHalf.shape[:2]
peppersNeg = 255 - peppersHalf[:, 256::-1]
finalCanvas = np.zeros(((2*height + width - 1), width * 2, 3), dtype=np.uint8)
print(width)

for col in range(width):
    finalCanvas[col:col + width, width + col] = peppersNeg[:, col]  ##The Top Right
    finalCanvas = finalCanvas[:, width*2::-1]
    finalCanvas[col:col + width, width + col] = peppersNeg[:, -col]  ##The top Left
    finalCanvas = finalCanvas[:, width*2::-1]

for col in range(width):
    finalCanvas[height + col:height + width + col, col] = peppersHalf[:, col]  ##Bottom Left
    finalCanvas = finalCanvas[:, width * 2::-1]
    finalCanvas[height + col:height + width + col, col] = peppersHalf[:, -col]  ##Bottom Right
    finalCanvas = finalCanvas[:, width*2::-1]

cv2.imshow("BEHOLD...THE BOX", finalCanvas)
cv2.imwrite("Peppers_Box.jpg", finalCanvas)
# Gamma Correction Of 1.5

gammaPeppers = ((peppers.astype('float32') / 255) ** (1 / 1.5))
gammaPeppers *= 255

# cv2.imshow("Gamma Corrected Peppers", gammaPeppers.astype('uint8'))
cv2.imwrite("Peppers_Gamma.tif", gammaPeppers.astype('uint8'))

# 50% Weighted Average
img1 = cv2.imread("standard_test_images/standard_test_images/peppers_color.tif")
img2 = cv2.imread("standard_test_images/standard_test_images/mandril_color.tif")
img3 = img1 // 2 + img2 // 2
redBorder = np.zeros((532, 532, 3), dtype=np.uint8)
redBorder[:, :, 2] = 255
redBorder[10:-10, 10:-10] = img3
cv2.imshow("Average", redBorder)
cv2.imwrite("Mandril_Border.tif", redBorder)
# Creates a black and white image from the average intensity of each point
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