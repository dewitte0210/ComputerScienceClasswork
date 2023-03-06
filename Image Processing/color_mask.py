import cv2
import numpy as np

image = cv2.imread("standard_test_images/berries.png")
hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
mask = np.logical_and((hsv_image[:, :, 0] > 25), (hsv_image[:, :, 0] < 179-15),(hsv_image[:,:,1] < 60))
mask = np.uint8(mask * 255)
kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (9, 9))
mask = cv2.dilate(mask, kernel, iterations=4)
mask = cv2.erode(mask, kernel, iterations=5)
mask = cv2.dilate(mask,kernel, iterations=1)


blueMask = np.logical_and((hsv_image[:,:,0] < 100),(hsv_image[:,:,0] > 150))
blueMask = np.uint8(mask * 255)
blueMask = cv2.dilate(blueMask,kernel, iterations = 1)
blueMask = cv2.erode(blueMask, kernel, iterations = 1)

image[mask == 255, :] = 0

cv2.imshow("Red", blueMask)
cv2.waitKey(0)
cv2.destroyAllWindows()
