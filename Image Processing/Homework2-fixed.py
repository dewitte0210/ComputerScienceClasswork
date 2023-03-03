import numpy as np
import cv2

def equalizeHistogram(image):
    histogram = np.histogram(image,bins=np.arange(257), density=True)[0]
    cdf = np.cumsum(histogram)
    intensities = np.uint8(np.round(255.*cdf))
    return intensities[image]


original = cv2.imread("standard_test_images/lake.tif")
halfIntensity = equalizeHistogram(original//2)
linearIncrease = np.copy(original)
linearIncrease[linearIncrease > 127] = 255
linearIncrease[linearIncrease < 128] += 128
linearIncrease = equalizeHistogram(linearIncrease)

cv2.imshow("Original | Half Intensity | Linear Increase", np.concatenate(((original, halfIntensity, linearIncrease)), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()