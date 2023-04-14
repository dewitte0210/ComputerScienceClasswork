import numpy as np
import cv2
import dct

img = cv2.imread("standard_test_images/pirate.tif", cv2.IMREAD_GRAYSCALE)
jpeg = np.abs(dct.dct_image(img))
jpeg /= np.max(jpeg)
dct.show_images(img)
cv2.imshow("JPEG", jpeg)
cv2.waitKey(0)
cv2.destroyAllWindows()