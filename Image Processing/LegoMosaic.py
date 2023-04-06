import numpy as np
import cv2
import pandas as pd
from PIL import Image

legoCSV = pd.read_csv(r"LEGOColors.csv")
legoRGB = np.float32(pd.DataFrame(legoCSV, columns=['Red','Green','Blue']).to_numpy() / 255.0)
num_colors = legoRGB.shape[0]

HEIGHT = 112.0

img = cv2.imread("standard_test_images/rose.png")
H, W = img.shape[:2]
img = Image.fromarray(img)
img = img.resize((round(HEIGHT * W / H), round(HEIGHT)), Image.LANCZOS)
img = (np.float32(img) / 255.0)
height, width = img.shape[:2]

kernel = np.array([[0,0,7], [3,5,1.0]]) / 16
for i in range(height):
    for j in range(width):
        b, g, r = img[i,j]
        for x in range(num_colors):
            if(legoRGB[0, x] < r ):
                bot = r - legoRGB[0,x]
                top = legoRGB[0,x+1] - r
                r = bot if bot<top else top
            if(legoRGB[1,x] < g):
                bot = g - legoRGB[1,x]
                top = legoRGB[1,x+1] - g
                g = bot if bot<top else top
            if(legoRGB[2,x] < b):
                bot = b - legoRGB[2,x+1]
                top = legoRGB[2,x+1] - b
                b = bot if bot<top else top
        bErr = img[i,j,0] - b
        gErr = img[i,j,1] - g
        rErr = img[i,j,2] - r  
        img[i:i+2, j-1:j+2, 0] += (bErr * kernel)
        img[i:i+2, j-1:j+2,1] += (gErr * kernel)
        img[i:i+2, j-1:j+2,2] += (rErr * kernel)
        img[i,j] = b, g, r

cv2.imshow("Lets Hope", img)
cv2.waitKey(0)
cv2.destroyAllWindows()