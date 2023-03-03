import numpy as np
import cv2
def sobelX(img):
    kernel = np.array([[-1,0,1],[-2,0,2],[-1,0,1]])
    changed = cv2.filter2D(img,-1,kernel)
    return changed

def sobelY(img):
    kernel = np.array([[-1,-2,-1],[0,0,0],[1,2,1]])
    changed = cv2.filter2D(img,-1,kernel)
    return changed

def boxBlur(img):
    kernel = np.array([[1,1,1],[1,1,1],[1,1,1.0]])
    kernel = kernel/9.0
    changed = cv2.filter2D(img,-1,kernel)
    return changed

def gaussianBlur(img):
    kernel = np.array([[1,4,6,4,1],[4,16,24,16,4],[6,24,36,24,6],[4,16,24,16,4],[1,4,6,4,1.0]])
    kernel = kernel/256.0
    changed = cv2.filter2D(img,-1,kernel)
    return changed

def vertEmboss(img):
    kernel = np.array([[0,1,0],[0,0,0],[0,-1,0]])
    changed = cv2.filter2D(img,-1,kernel)
    return changed

def horiEmboss(img):
    kernel = np.array([[0,0,0],[1,0,-1],[0,0,0]])
    changed = cv2.filter2D(img,-1,kernel)
    return changed

def unsharp(img):
    blurred = boxBlur(img)
    fine = img - blurred
    changed = img + (5 * fine)
    return changed

def sharpen(img):
    kernel = np.array([1,0,-1])
    changed = cv2.filter2D(img, -1, kernel)
    return img + changed

def doubleVis(img):
    kernel = np.array([[2,1,0,0,0,1,2],
                       [2,1,0,0,0,1,2],
                       [2,1,0,0,0,1,2],
                       [2,1,0,0,0,1,2],
                       [2,1,0,0,0,1,2],
                       [2,1,0,0,0,1,2],
                       [2,1,0,0,0,1,2]])
    kernel = kernel * (1/42)
    changed = cv2.filter2D(img, -1, kernel)
    return changed

def quadVis(img):
    kernel = np.array([[2,2,2,2,0,0,0,0,2,2,2,2],
                       [2,2,2,2,0,0,0,0,2,2,2,2],
                       [2,2,2,2,0,0,0,0,2,2,2,2],
                       [2,2,2,2,0,0,0,0,2,2,2,2],
                       [0,0,0,0,0,0,0,0,0,0,0,0],
                       [0,0,0,0,0,0,0,0,0,0,0,0],
                       [0,0,0,0,0,0,0,0,0,0,0,0],
                       [0,0,0,0,0,0,0,0,0,0,0,0],
                       [2,2,2,2,0,0,0,0,2,2,2,2],
                       [2,2,2,2,0,0,0,0,2,2,2,2],
                       [2,2,2,2,0,0,0,0,2,2,2,2],
                       [2,2,2,2,0,0,0,0,2,2,2,2]])
    kernel = kernel * (1/128)
    changed = cv2.filter2D(img,-1,kernel)
    return changed

def gradientMagnitude(img):
    imgx = sobelX(img)
    imgy = sobelY(img)
    changed = np.sqrt(imgx**2 + imgy**2)
    return changed