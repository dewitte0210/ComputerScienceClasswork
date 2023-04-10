import numpy as np
import cv2
from skimage.transform import radon



#img = cv2.imread("standard_test_images/quadrilateral.png", cv2.IMREAD_GRAYSCALE)
img = cv2.imread("standard_test_images/quadrilateral.png", cv2.IMREAD_GRAYSCALE)
print(img.shape)
rImg = radon(img, np.linspace(0.0, 180.0, num=540, endpoint=False))
rImg = rImg / np.max(rImg)
rImg[rImg < 0.3] = 0
rImg[rImg != 0 ] = 255
kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3,3))
rImg = cv2.erode(rImg,kernel,iterations = 2)
lines = []

#get the polar coordinates of each line
for i in range(len(rImg)):
    for j in range(len(rImg[1])):
        if rImg[i,j] == 255:
            p, theta = i, j/3
            duplicate = False;
            for n in range(len(lines)):
                if (p > lines[n][0] - 5 and p < lines[n][0] + 5) or (theta > lines[n][1] - 5 and theta < lines[n][1] + 5):
                    duplicate = True
            if not duplicate:
                lines.append((p, theta))

#Converts the polar coordinates to x,y 
for i in range(len(lines)):
    coords = (lines[i][0] * np.cos(lines[i][1]), lines[i][0] * np.sin(lines[i][1]))
    #print(coords)
    slope = np.float32(coords[0] / coords[1]) * -1 # this is the slope of our perpendicular line
    b = (slope * coords[0]  *-1) + coords[1]
    lines[i] = (slope, b)

#print(lines)    
intersects = []
#Calculate the intersections of the line
for i in range(len(lines)):
    for k in range(len(lines)):
        if i != k:
            x = (lines[i][1] - lines[k][1]) / (lines[i][0] - lines[k][0])
            y = lines[i][0] * x + lines[i][1]
            if (lines[i][0] < 0 and lines[k][0] > 0 or (lines[i][0] > 0 and lines[k][0] < 0)):
                duplicate = False
                for j in range(len(intersects)):
                    if(x == intersects[j][0] or y == intersects[j][1]):
                        duplicate = True
                if duplicate == False:
                    intersects.append((x,y))
print(intersects)

    
cv2.imshow("Quadrilateral", img)
cv2.imshow("Radon Transform", rImg)
cv2.waitKey(0)
cv2.destroyAllWindows()
