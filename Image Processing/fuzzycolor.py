import cv2
import numpy as np

colors = {"red": 1.0, "yellow": np.exp(1j * np.pi / 3),
          "green": np.exp(1j * 2 * np.pi / 3), "cyan": np.exp(1j * np.pi),
          "blue": np.exp(1j * 4 * np.pi / 3), "magenta": np.exp(1j * 5 * np.pi / 3),
          "purple": np.exp(1j * 4.8328), "orange": np.exp(1j * np.pi / 6)}


def triangular(z, center):
    x = np.zeros(z.shape)
    condition = np.logical_and(z >= center - 60.0, z <= center + 60.0)
    x[condition] = 1.0 - np.abs((z[condition] - center)) / 60.0
    return x


def mu(z, center):
    return np.maximum(triangular(z, center), triangular(z - 360.0, center))


def change_color(z, color=["red", "yellow", "green", "cyan", "blue", "magenta"]):
    x = mu(z, 0) * colors[color[0]] + mu(z, 60) * colors[color[1]] + \
        mu(z, 120) * colors[color[2]] + mu(z, 180) * colors[color[3]] + \
        mu(z, 240) * colors[color[4]] + mu(z, 300) * colors[color[5]]
    return np.float32((np.angle(x) % (2 * np.pi)) * 180.0 / np.pi)


COLORS = ["orange", "yellow", "green", "cyan", "blue", "orange"]

image = np.float32(cv2.imread("standard_test_images/rose.png") / 255.0)
hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
hsv[:, :, 0] = change_color(hsv[:, :, 0], COLORS)
color_change = cv2.cvtColor(hsv, cv2.COLOR_HSV2BGR)
cv2.imshow("Color Change", np.concatenate((image, color_change), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()
