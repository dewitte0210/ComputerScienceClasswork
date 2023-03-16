import numpy as np
import cv2

bunny = cv2.imread("standard_test_images/bunny.png")[::3, ::3]
bunny[bunny < 128] = 0
bunny[bunny >= 128] = 255
kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (15,15))
dilation = cv2.dilate(bunny, kernel,iterations=1)
outline = 255- (dilation - bunny)
cv2.imshow("bunny", np.concatenate((bunny, dilation,outline), axis = 1))
cv2.waitKey(0)
cv2.destroyAllWindows()
