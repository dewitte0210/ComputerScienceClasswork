import numpy as np
import cv2
from scipy.fft import dctn

def pHash(img):
    shrunk = cv2.resize(img, (32,32))
    shrunk = dctn(shrunk)[:8,:8].flatten()
    boolean = shrunk > (np.average(shrunk[1:]))
    return np.packbits(boolean)
    
def getHash(img):
    shrunk = cv2.resize(img, (9,8))
    boolean = shrunk[:-1] > shrunk[1:]
    return np.packbits(boolean)

def compareHash(hash1, hash2):
    return np.sum(np.unpackbits(hash1 ^ hash2))

img = cv2.imread("standard_test_images/pirate.tif", cv2.IMREAD_GRAYSCALE)
img2 = cv2.imread("standard_test_images/livingroom.tif", cv2.IMREAD_GRAYSCALE)
print(pHash(img))
print(pHash(img2))
print(compareHash(pHash(img), pHash(img2)))