import cv2
import numpy as np

img = cv2.imread("standard_test_images/peppers_color.tif")
 #Scale the Image 50%
img = img[::2,::2]
#Get width and height Uses the slicing to grab just height and width and not channels
height, width = img.shape[:2] 

##Get a blank canvas that is the correct size to hold the skewed image
skew = np.zeros((2*height-1, width, 3), dtype=np.uint8)

for row in range(width):
        skew[row:row+height, row, :] = img[:, row]


cv2.imshow("peppers", skew)
cv2.waitKey(0)
cv2.destroyAllWindows()