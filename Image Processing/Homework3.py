import filters as fil
import cv2
import numpy as np

img = cv2.imread("standard_test_images/cameraman.tif",cv2.IMREAD_GRAYSCALE)/255.0
"""
cv2.imwrite("SobelX.tif", fil.sobelX(img))
cv2.imwrite("SobelY.tif", fil.sobelY(img))
cv2.imwrite("Box-Blur.tif", fil.boxBlur(img))
cv2.imwrite("Gaussian-Blur.tif", fil.gaussianBlur(img))
cv2.imwrite("Vertical-Emboss.tif", fil.vertEmboss(img))
cv2.imwrite("Horizontal-Emboss.tif", fil.horiEmboss(img))
cv2.imwrite("Unsharp-mask.tif", fil.unsharp(img))
cv2.imwrite("Sharpend.tif", fil.sharpen(img))
cv2.imwrite("Double-Vision.tif", fil.doubleVis(img))
cv2.imwrite("Quad-Vision.tif", fil.quadVis(img))
"""
#cv2.imshow("GradMag", fil.gradientMagnitude(img))
#STEP 4
whiteBox = np.zeros((512,512), dtype=np.uint8) /255.0
whiteBox[224:288, 224:288] = 1
gaussBox = cv2.GaussianBlur(whiteBox,(15,15),0,0)
blurBox = cv2.boxFilter(whiteBox,-1,(15,15))
cv2.imshow("Original | Gaussian | Box Blur", np.concatenate((whiteBox, gaussBox, blurBox), axis=1))

#STEP 5
kernel = np.array([[1,0,0,0,0,0,0],
                    [1,1,0,0,0,0,0],
                    [1,1,1,0,0,0,0],
                    [1,1,1,1,0,0,0],
                    [1,1,1,1,1,0,0],
                    [1,1,1,1,1,1,0],
                    [1,1,1,1,1,1,1]])/28.0
newBox = cv2.filter2D(whiteBox,-1,kernel)
smallBox = np.zeros((512,512), dtype=np.uint8)/255.0
smallBox[254:258,254:258] = 1
newSmall = cv2.filter2D(smallBox,-1,kernel)
cv2.imshow("Triangle Filter", np.concatenate((whiteBox,newBox,newSmall),axis=1))

cv2.waitKey(0)
cv2.destroyAllWindows()
