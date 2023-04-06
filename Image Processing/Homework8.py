import numpy as np
import cv2
from skimage.transform import radon

#img = cv2.imread("standard_test_images/quadrilateral.png", cv2.IMREAD_GRAYSCALE)
img = cv2.imread("standard_test_images/quadrilateral.png", cv2.IMREAD_GRAYSCALE)
rImg = radon(img, np.linspace(0.0, 180.0, num=540, endpoint=False))
rImg = rImg / np.max(rImg)
rImg[rImg < 0.3] = 0
rImg
print(img.shape)
print(rImg.shape)

#Detecting the lines

cv2.imshow("Quadrilateral", img)
cv2.imshow("Radon Transform", rImg)
cv2.waitKey(0)
cv2.destroyAllWindows()