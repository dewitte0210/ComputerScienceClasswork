import numpy as np
import cv2

Shades = 2.0
img = (Shades - 1) * cv2.imread("standard_test_images/lake.tif", cv2.IMREAD_GRAYSCALE)/255.0
kernel = np.array([[0,0,7], [3,5,1.0]]) / 16

for i in range(1,len(img)-1):
    for j in range(1,len(img[1])-1):
        value = np.round(img[i,j])
        error = img[i,j] - value
        img[i:i+2, j-1:j+2] += (error * kernel)
        img[i,j] = value

img = img / (Shades - 1)
cv2.imshow("Read And Show", img)
cv2.waitKey(0)
cv2.destroyAllWindows()