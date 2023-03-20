import cv2
import numpy as np


def triangular(z, a, b, c):
    x = np.zeros(z.shape)
    condition = np.logical_and(z >= a, z < b)
    x[condition] = (z[condition] - a) / (b - a)
    condition = np.logical_and(z >= b, z < c)
    x[condition] = 1 - (z[condition] - b) / (c - b)
    return x


def trapezoid(z, a, b):
    x = np.zeros(z.shape)
    condition = np.logical_and(z >= a, z < b)
    x[condition] = (z[condition] - a) / (b - a)
    condition = z >= b
    x[condition] = 1
    return x


def decr_trapezoid(z, a, b):
    return 1 - trapezoid(z, a, b)


def defuzz(z, a, b, c, darker=0, gray=0.5, brighter=1.0):
    mu_dark = decr_trapezoid(z, a, b)
    mu_gray = triangular(z, a, b, c)
    mu_bright = trapezoid(z, b, c)
    return (mu_dark*darker+mu_gray*gray+mu_bright*brighter)/(mu_dark+mu_gray+mu_bright)


img = cv2.imread("standard_test_images/livingroom.tif", cv2.IMREAD_GRAYSCALE)/255.0
cv2.imshow("Fuzzy Contrast", np.concatenate((img, defuzz(img, 0.15, 0.5, 0.85)), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()
