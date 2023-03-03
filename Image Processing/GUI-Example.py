import cv2
import numpy as np

img = cv2.imread("standard_test_images/cameraman.tif")

def update_blur(x):
    display_image = cv2.GaussianBlur(img, (2 * x + 1, 2 * x + 1),0,0)
    cv2.imshow("Simple GUI", display_image)

# Create a named window
cv2.namedWindow("Simple GUI")

cv2.createTrackbar("Blur Size", "Simple GUI", 0,100, update_blur)

cv2.imshow("Simple GUI", img)
cv2.waitKey(0)
cv2.destroyAllWindows()