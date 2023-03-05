import numpy as np
import cv2
import filters as fil
img = cv2.imread("standard_test_images/peppers_color.tif")
prev = 0
cv2.cvtColor(img,cv2.COLOR_BGR2HLS)

#STEP 1 HUE ROTATION

def updateColor(val):
    global prev
    img[:,:,0] = (img[:,:,0] + (val - prev)) % 256
    prev = val
    cv2.cvtColor(img,cv2.COLOR_HLS2BGR)
    cv2.imshow("Color Change GUI", img)
    cv2.cvtColor(img,cv2.COLOR_BGR2HLS)

cv2.namedWindow("Color Change GUI")
cv2.createTrackbar("Hue Rotation","Color Change GUI",0,255,updateColor)
updateColor(0)
cv2.waitKey(0)
cv2.destroyAllWindows()

#STEP 2 GAMA CORRECTION

img2 = cv2.imread("standard_test_images/peppers_color.tif")
cv2.cvtColor(img2, cv2.COLOR_BGR2HLS)
def updateGamma(gam):
    newImage = np.copy(img2) / 255.0
    gam /= 10.0
    if(gam == 0):
        gam = 0.1
    newImage **= (1/gam)
    newImage *= 255
    cv2.cvtColor(np.uint8(newImage), cv2.COLOR_HLS2BGR)
    cv2.imshow("Gamma Correct GUI", np.uint8(newImage))
    cv2.cvtColor(np.uint8(newImage), cv2.COLOR_BGR2HLS)


cv2.namedWindow("Gamma Correct GUI")
cv2.createTrackbar("Gamma Correction", "Gamma Correct GUI", 0,30,updateGamma)
updateGamma(1)
cv2.waitKey(0)
cv2.destroyAllWindows()

#STEP 3 Sharpening the L channel
img3 = cv2.imread("standard_test_images/peppers_color.tif")
cv2.cvtColor(img3, cv2.COLOR_BGR2HLS)
img3[:,:,1] = fil.unsharp(img3[:,:,1])
cv2.cvtColor(img3, cv2.COLOR_HLS2BGR)
cv2.imshow("Sharpend L", img3)
cv2.waitKey(0)
cv2.destroyAllWindows()