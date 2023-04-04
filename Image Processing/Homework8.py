import numpy as np
import cv2
from skimage.transform import radon

img = cv2.imread("standard_test_images/quadrilateral.png", cv2.IMREAD_GRAYSCALE)

rImg = radon(img, np.linspace(0.0, 180.0, num=500, endpoint=False))
rImg = rImg / np.max(rImg)

#rImg[rImg < .3] = 0
#rImg[rImg > .2] = 255
cv2.imshow("Quadrilateral", img)
cv2.imshow("Radon Transform", rImg)
cv2.waitKey(0)
cv2.destroyAllWindows()