import cv2
import numpy as np
from scipy.fft import fft2, ifft2, fftshift, ifftshift


def get_dft(img):
    return fftshift(fft2(img))


def get_image(img):
    img2 = np.real(ifft2(ifftshift(img)))
    img2[img2 > 255] = 255
    img2[img2 < 0] = 0
    return np.uint8(np.round(img2))


def dft_image(img):
    img2 = np.log(1.0 + np.abs(img))
    return np.uint8(np.round(255 * (img2 - np.min(img2)) / (np.max(img2) - np.min(img2))))


def show_both(img):
    cv2.imshow("DFT / Reconstructed Image", np.concatenate((dft_image(img), get_image(img)), axis=1))
    cv2.waitKey(0)
    cv2.destroyAllWindows()


image = cv2.imread("standard_test_images/pirate.tif", cv2.IMREAD_GRAYSCALE)
dft = get_dft(image)
dft[254:258, 254:258] = 0

show_both(dft)
