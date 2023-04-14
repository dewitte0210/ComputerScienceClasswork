import numpy as np


def Haar(image, n=2):
    img = np.copy(image)
    if n == 0:
        return img
    height, width = np.shape(img)
    img.shape = (height, width // 2, 2)
    return np.concatenate((Haar(0.5 * (img[:, :, 0] + img[:, :, 1]), n - 1), 0.5 * (img[:, :, 0] - img[:, :, 1])),
                          axis=-1)


def Haar_2d(img, n=2):
    return Haar(Haar(img, n).T, n).T


def Haar_inv(image, n=2):
    img = np.copy(image)
    if n == 0:
        return img
    num_cols = img.shape[1] // (2 ** n)
    sums = img[:, :num_cols]
    diffs = img[:, num_cols:2 * num_cols]
    evens = (sums + diffs)
    odds = (sums - diffs)
    img[:, :2 * num_cols:2] = evens
    img[:, 1:2 * num_cols:2] = odds
    return Haar_inv(img, n-1)


def Haar_inv_2d(img, n=2):
    return Haar_inv(Haar_inv(img, n).T, n).T
