import cv2
import numpy as np

canvas = np.zeros((200,200), dtype=np.uint8)
canvas[75:125, 75:125] = 255

boxBlur = cv2.blur(canvas, (19,19))
gauss = cv2.GaussianBlur(canvas,(19,19),0,0)
cv2.imshow("canvas | boxBlur | Gaussian Blur", np.concatenate((canvas, boxBlur,gauss),axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()