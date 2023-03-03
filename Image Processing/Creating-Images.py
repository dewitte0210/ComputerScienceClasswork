import cv2
import numpy as np

#Creates an array where the value of each index is zero
img = np.zeros((512,512,3), dtype = np.uint8)
#Use np.full(shape, value, type) to fill with a specific value
peppers = cv2.imread("standard_test_images/peppers_color.tif")
img2 = np.zeros((532,532,3), dtype = np.uint8)
img2[:,:,0] = 255
img2[10:522,10:522,:] = peppers
## can also do img2[10:-10,10:-10,:] to negative index the end

cv2.imshow("Read And Show", img2)
cv2.waitKey(0)
cv2.destroyAllWindows()