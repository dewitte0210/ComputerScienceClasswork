import numpy as np
import cv2

def equalizeHistogram(img):
    histogram = np.histogram(img,bins=np.arange(257),density=True)[0]
    cdf = np.cumsum(histogram)
    intensities = np.uint8(np.round(255.*cdf))
    return intensities[img]

img = cv2.imread("standard_test_images/peppers_color.tif")
HSL = cv2.imread("standard_test_images/peppers_color.tif")
HSV = cv2.imread("standard_test_images/peppers_color.tif")
HSL = cv2.cvtColor(HSL,cv2.COLOR_BGR2HLS)
HSV = cv2.cvtColor(HSV,cv2.COLOR_BGR2HSV)
HSL[:,:,1] = equalizeHistogram(HSL[:,:,1])
HSV[:,:,2] = equalizeHistogram(HSV[:,:,2])
cv2.imshow("Original | HSL | HSV", np.concatenate((img,HSL,HSV),axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()