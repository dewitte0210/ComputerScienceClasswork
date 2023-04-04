import numpy as np
import cv2
from skimage.transform import radon

image = np.zeros((512, 512))
image[128:-128, 128:-128] = 1.0
image[192:-192, 192:-192] = 0.0

cv2.imshow("Original Image", image)
cv2.waitKey(0)
cv2.destroyAllWindows()

r_image = radon(image, np.linspace(0.0, 180.0, num=500, endpoint=False))

cv2.imshow("Radon Transform", r_image / np.max(r_image))
cv2.waitKey(0)
cv2.destroyAllWindows()
