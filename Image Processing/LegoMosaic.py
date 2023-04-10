import numpy as np
import cv2
import pandas as pd
from PIL import Image

legoCSV = pd.read_csv(r"LEGOColors.csv")
legoRGB = np.float32(pd.DataFrame(legoCSV, columns=['Red','Green','Blue']).to_numpy() / 255.0)
num_colors = legoRGB.shape[0]
HEIGHT = 128.0

img = cv2.imread("standard_test_images/clocktower.jpg")
H, W = img.shape[:2]
img = Image.fromarray(img)
img = img.resize((round(HEIGHT * W / H), round(HEIGHT)), Image.LANCZOS)
img = (np.float32(img) / 255.0)
height, width = img.shape[:2]

for i in range(1,height - 1):
    for j in range(1,width - 1):
        min_dist = np.argmin(np.sum((img[i,j] - legoRGB[:,::-1]) ** 2,axis=1))
        value = legoRGB[min_dist, ::-1]
        error = img[i,j] - value
        img[i, j + 1] += error * 7/16
        img[i + 1, j-1] += error * 3/16
        img[i + 1, j] += error * 5/16
        img[i + 1, j+1] += error / 16
        img[i,j] = value
img = np.uint8(img * 255)
img = img.repeat(4, 0).repeat(4,1)
cv2.imshow("Lets Hope", img)
cv2.waitKey(0)
cv2.destroyAllWindows()