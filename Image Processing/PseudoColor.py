import numpy as np
import cv2


''' Color Slicing
red = 63
green = 127
blue = 191

img = cv2.imread("standard_test_images/x-ray.jpg", cv2.IMREAD_GRAYSCALE)
height, width = img.shape
pcImage = np.zeros((height,width,3), dtype=np.uint8)
pcImage[:,:] = np.array([0,255,255], dtype=np.uint8)
pcImage[img < blue] = np.array([255,0,0], dtype=np.uint8)
pcImage[img < green] = np.array([0,255,0], dtype=np.uint8)
pcImage[img < red] = np.array([0,0,255], dtype=np.uint8)
'''
color = np.zeros((256,3), dtype=np.uint8)
for i in range(0,256):
    color[i,0] = 255 - i
    color[i,1] =  0 + i

img = cv2.imread("standard_test_images/x-ray.jpg", cv2.IMREAD_GRAYSCALE)
pcImage = color[img]
cv2.imshow("X-Ray", pcImage)
cv2.waitKey(0)
cv2.destroyAllWindows()