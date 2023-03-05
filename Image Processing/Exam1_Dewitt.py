import numpy as np
import cv2

#SETP 1

img1 = cv2.imread("standard_test_images/peppers_color.tif") / 1.0
grayscale = (img1[:,:,0] * .375) + (img1[:,:,1] * .5) + (img1[:,:,1] * .125)
cv2.imshow("grayscale conversion", np.uint8(grayscale))
cv2.waitKey(0)
cv2.destroyAllWindows()

#STEP 2
grayscale = grayscale / 255.0
grayscale **= (1/1.3)
cv2.imshow("Gamma Correct", grayscale)
cv2.waitKey(0)
cv2.destroyAllWindows()

#SETP 3
kernel = np.array([[1,2,1],
                   [2,4,2],
                   [1,2,1]])/16
grayscale = cv2.filter2D(grayscale,-1,kernel)
cv2.imshow("Gausian Blur", grayscale)
cv2.waitKey(0)
cv2.destroyAllWindows()

#STEP 4
grayscale *= 255
histogram = np.histogram(grayscale, bins=np.arange(257), density=True)[0]
cdf = np.cumsum(histogram)
intensities = np.uint8(np.round(255.*cdf))
equalized = intensities[np.uint8(grayscale)]
cv2.imshow("Histogram Equalized", equalized)
cv2.waitKey(0)
cv2.destroyAllWindows()

#STEP 5
equalized = equalized / 255.0
equalized **= (1/1.3)
cv2.imshow("Gamma Correct 2.0", equalized)
cv2.waitKey(0)
cv2.destroyAllWindows()

#STEP 6
equalized = equalized[:, ::-1]
cv2.imshow("Flipped", equalized)
cv2.waitKey(0)
cv2.destroyAllWindows()

#STEP 7
equalized[equalized > 0.75] = 0
cv2.imshow(".75 -> 0", equalized)
cv2.waitKey(0)
cv2.destroyAllWindows()

#STEP 8
equalized *= 255
cv2.imwrite("exam_Dewitt.png", equalized)