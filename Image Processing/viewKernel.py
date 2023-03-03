import cv2
import numpy as np
from scipy.fft import fft2, ifft2, fftshift, ifftshift


def get_dft(img):
    return fftshift(fft2(img))


def dft_image(img):
    img2 = np.log(1.0 + np.abs(img))
    return np.uint8(np.round(255 * (img2 - np.min(img2)) / (np.max(img2) - np.min(img2))))


def get_image(img):
    img2 = np.real(ifftshift(ifft2(ifftshift(img))))
    img2[img2 > 255] = 255
    img2[img2 < 0] = 0
    return np.uint8(np.round(img2))


kernel = np.array([[0, -1, 0],
                   [-1, 4, -1],
                   [0, -1, 0]], dtype=np.double)

canvas = np.zeros((512, 512), dtype=np.double)

canvas[254:257, 254:257] = kernel
dft = get_dft(canvas)

image = cv2.imread("standard_test_images/peppers_color.tif", cv2.IMREAD_GRAYSCALE) * 1.0
img_dft = get_dft(image)
convolved = get_image(dft * img_dft)

cv2.imshow("Convolution Theorem",
           np.concatenate((np.uint8(image), convolved, dft_image(get_dft(canvas))), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()
