import numpy as np
import cv2

#SETP 1

coin = cv2.imread("Coins/coin5-challenge.png")
cv2.cvtColor(coin, cv2.COLOR_BGR2HSV)
mask = coin [:,:,1] < 140
mask = np.uint8(mask * 255)
mask[mask < 128] = 0
mask[mask > 127] = 255
kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (11,11))
mask = cv2.dilate(mask,kernel, iterations=2)
cv2.cvtColor(coin, cv2.COLOR_HSV2BGR)
cv2.imshow("Coins", coin)
cv2.imshow("Mask", mask)
cv2.imwrite("coins_challenge_mask.png", mask)


#STEP 2
original = cv2.imread("standard_test_images/pirate.tif", cv2.IMREAD_GRAYSCALE)
noisy = cv2.imread("washed_out_images/noisy_both.png" , cv2.IMREAD_GRAYSCALE)
noisy[noisy == 0] = 255
kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3,3))
blurryNoise = cv2.morphologyEx(noisy, cv2.MORPH_OPEN,kernel, iterations=2)
noisy[noisy == 255] = blurryNoise[noisy == 255]
cv2.imshow("Original | noisy", np.concatenate((original, noisy), axis=1))
cv2.imwrite("noisy_both_fixed.png", noisy)

cv2.waitKey(0)
cv2.destroyAllWindows()