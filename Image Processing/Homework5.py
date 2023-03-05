import numpy as np
import cv2
from scipy.fft import fft2, ifft2, fftshift, ifftshift

def equalizeHistogram(img):
    histogram = np.histogram(img, bins=np.arange(257), density=True)[0]
    cdf = np.cumsum(histogram)
    intensities = np.uint8(np.round(255.*cdf))
    return intensities[np.uint8(img)]

# Takes in an image and returns the DFT
def get_dft(img):
    return fftshift(fft2(img))

# Takes in a DFT and returns an uint8 image
def get_image(img):
    img2 = np.real(ifft2(ifftshift(img)))
    img2[img2 > 255] = 255
    img2[img2 < 0] = 0
    return np.uint8(np.round(img2))

# Takes in a DFT and returns an uint8 image of the DFT
def dft_image(img):
    img2 = np.log(1.0 + np.abs(img))
    return np.uint8(np.round(255 * (img2 - np.min(img2)) / (np.max(img2) - np.min(img2))))

# Accepts a DFT and outputs the image and DFT side by side
def show_both(img):
    cv2.imshow("DFT / Reconstructed Image", np.concatenate((dft_image(img), get_image(img)), axis=1))

## STEP 1. IMAGE RECONSTRUCTION

image = cv2.imread("HalftoneImages/halftone.png", cv2.IMREAD_GRAYSCALE) * 1.0
dft = get_dft(image)
print(image.shape)

saved = np.copy(dft[286:486, 299:499])
dft[:,:] = 0
dft[286:486, 299:499] = saved
newImage = get_image(dft)
newImage = cv2.GaussianBlur(newImage, (15,15),0,0)
newDft = get_dft(newImage)
show_both(newDft)
cv2.imwrite("HalftoneImages/halftoneFixed.png", get_image(newDft))

#scan.png
scan = cv2.imread("HalftoneImages/scan.png", cv2.IMREAD_GRAYSCALE) * 1.0
scan = scan[::2,::2]
print(scan.shape)
scanDft = get_dft(scan)
show_both(scanDft)
saved = np.copy(scanDft[184:584, 312:712])
scanDft[:,:] = 0
scanDft[184:584,312:712] = saved
scan = get_image(scanDft)
scan = cv2.GaussianBlur(scan, (5,5),0,0)
scanDft = get_dft(scan)
cv2.imwrite("HalftoneImages/scanFixed.png",get_image(scanDft))

cv2.waitKey(0)
cv2.destroyAllWindows()

## STEP 2. COLOR SPACE CONVERSIONS

img = cv2.imread("standard_test_images/peppers_color.tif")
HSL = cv2.imread("standard_test_images/peppers_color.tif")
HSV = cv2.imread("standard_test_images/peppers_color.tif")
HSL = cv2.cvtColor(HSL,cv2.COLOR_BGR2HLS)
HSV = cv2.cvtColor(HSV,cv2.COLOR_BGR2HSV)
HSL[:,:,1] = equalizeHistogram(HSL[:,:,1])
HSV[:,:,2] = equalizeHistogram(HSV[:,:,2])
HSL = cv2.cvtColor(HSL, cv2.COLOR_HLS2BGR)
HSV = cv2.cvtColor(HSV, cv2.COLOR_HSV2BGR)
cv2.imshow("Original | HSL | HSV", np.concatenate((img,HSL,HSV),axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()



