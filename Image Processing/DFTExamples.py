import cv2
import numpy as np
from scipy.fft import fft2, ifft2, fftshift


def get_dft_image(img):
    dft = np.log(1.0+np.abs(fftshift(fft2(img))))
    dft = (dft-np.min(dft))/(np.max(dft)-np.min(dft))
    return dft


v_bar = np.zeros((512, 512), dtype=np.double)
v_bar[:, 128:-128] = 1.0
cv2.imshow("Vertical Bar", np.concatenate((v_bar, get_dft_image(v_bar)), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()

h_bar = np.zeros((512, 512), dtype=np.double)
h_bar[128:-128, :] = 1.0
cv2.imshow("Vertical Bar", np.concatenate((h_bar, get_dft_image(h_bar)), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()

square = np.zeros((512, 512), dtype=np.double)
square[128:-128, 128:-128] = 1.0
cv2.imshow("Square", np.concatenate((square, get_dft_image(square)), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()

grid = np.zeros((512, 512), dtype=np.double)
grid[::8] = 1.0
grid[:, ::8] = 1.0
cv2.imshow("Grid", np.concatenate((grid, get_dft_image(grid)), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()

circle = np.zeros((512, 512), dtype=np.uint8)
circle = cv2.circle(circle, (256, 256), radius=128, color=(255, 255, 255), thickness=-1,
                    lineType=cv2.LINE_AA) / 255.0
cv2.imshow("Circle", np.concatenate((circle, get_dft_image(circle)), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()

noise = np.random.randn(512, 512)
cv2.imshow("Noise", np.concatenate((noise, get_dft_image(noise)), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()

camera_man = cv2.imread("standard_test_images/cameraman.tif", cv2.IMREAD_GRAYSCALE)/255.0
cv2.imshow("Camera Man", np.concatenate((camera_man, get_dft_image(camera_man)), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()

blurred = cv2.GaussianBlur(camera_man, (31, 31), 0, 0)
cv2.imshow("Blurred", np.concatenate((blurred, get_dft_image(blurred)), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()
