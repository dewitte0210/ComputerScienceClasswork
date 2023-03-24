import numpy as np
import cv2

coin = cv2.imread("Coins/coin1.png")
cv2.cvtColor(coin, cv2.COLOR_BGR2HSV)
#mask = np.logical_and((coin[:,:,0] > 5), coin[:,:,0] < 40)
mask = coin [:,:,1] < 180
mask = np.uint8(mask * 255)
mask[mask < 128] = 0
mask[mask > 127] = 255
#kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (11,11))
#mask = cv2.dilate(mask,kernel, iterations=2)
cv2.cvtColor(coin, cv2.COLOR_HSV2BGR)
cv2.imshow("Coins", coin)
cv2.imshow("Mask", mask)
cv2.waitKey(0)
cv2.destroyAllWindows()