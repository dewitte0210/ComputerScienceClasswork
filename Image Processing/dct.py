import numpy as np
import cv2

Q = np.array([[16, 11, 10, 16, 24, 40, 51, 61],
              [12, 12, 14, 19, 26, 58, 60, 55],
              [14, 13, 16, 24, 40, 57, 69, 56],
              [14, 17, 22, 29, 51, 87, 80, 62],
              [18, 22, 37, 56, 68, 109, 103, 77],
              [24, 35, 55, 64, 81, 104, 113, 92],
              [49, 64, 78, 87, 103, 121, 120, 101],
              [72, 92, 95, 98, 112, 100, 103, 99]], dtype=np.double)  *2.0


def get_basis():
    basis = np.zeros((8, 8, 8, 8), dtype=np.double)
    values = (np.arange(8) + 0.5) * np.pi / 8
    for i in range(8):
        for j in range(8):
            basis[i, j] = np.cos(values * i)[:, None] * np.cos(values * j)[None, :]
    mags = np.sqrt(np.sum(basis ** 2.0, axis=(2, 3)))
    return basis / mags[:, :, None, None]


def dct_image(image):
    height, width = image.shape
    img = np.copy(image) - 128.0
    basis = get_basis()
    for row in range(0, height, 8):
        for col in range(0, width, 8):
            img[row:row + 8, col:col + 8] = np.sum(basis * img[None, None, row:row + 8, col:col + 8], axis=(2, 3)) / Q
    return np.round(img)


def idct_image(image):
    height, width = image.shape
    img = np.zeros((height, width))
    basis = get_basis()
    for row in range(0, height, 8):
        for col in range(0, width, 8):
            img[row:row + 8, col:col + 8] = np.sum(
                basis * image[row:row + 8, col:col + 8, None, None] * Q[:, :, None, None], axis=(0, 1))
    img = img+128.0
    img[img > 255.0] = 255.0
    img[img < 0.0] = 0.0
    return np.round(img)


def show_images(image):
    height, width = image.shape
    compressed = dct_image(image)
    decompressed = np.uint8(idct_image(compressed))
    zeros = (np.abs(compressed) < 1.0)
    print(np.sum(zeros)*1.0/(height*width))
    zeros = np.uint8(zeros*255.0)
    cv2.imshow("Original/Zeros/Decompressed", np.concatenate((image, zeros, decompressed), axis=1))
    cv2.waitKey(0)
    cv2.destroyAllWindows()
