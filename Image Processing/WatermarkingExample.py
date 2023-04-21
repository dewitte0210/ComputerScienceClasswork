import numpy as np
import cv2
from scipy.fft import dctn, idctn
img = cv2.imread("standard_test_images/pirate.tif", cv2.IMREAD_GRAYSCALE)
''' This is a Fragile Watermark technique
img = (img//2)  * 2
img[-64:, -64:] += 1
cv2.imwrite("pirate.jpg", img, [int(cv2.IMWRITE_JPEG_QUALITY), 90])
img = cv2.imread("pirate.jpg", cv2.IMREAD_GRAYSCALE)
cv2.imshow("Pireate", (img % 2)  * 255)
'''
k = 100 #num of hidden values
r = np.random.randn(k) #our fingerprint
alpha = 0.1
image_dct = dctn(img)
max_indicies = np.unravel_index(np.argsort(np.abs(image_dct), axis = None)[-k:], image_dct.shape)
image_dct[max_indicies] * (1.0 +alpha*r)
imageFP = idctn(image_dct)
imageFP[imageFP < 0.0] = 0.0
imageFP[imageFP > 255.0] = 255.0
imageFP = np.uint8(np.round(imageFP))
cv2.imwrite("imageFP.jpg", imageFP, [int(cv2.IMWRITE_JPEG_QUALITY),20])
image_dct = dctn(img)
imageFP_dct = dctn(cv2.imread("imageFP.jpg", cv2.IMREAD_GRAYSCALE))
W = ((imageFP_dct[max_indicies]/image_dct[max_indicies]) -1.0)/alpha
print(W)
print(r)
print(np.corrcoef(W,r))