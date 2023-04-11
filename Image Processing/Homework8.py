import numpy as np
import cv2
from skimage.transform import radon

'''
This the answer gotten by my code.
topLeftAngle:  47.15356456834958
botLeftAngle:  100.8684225867826
botRightAngle:  154.21827538914144
topRightAngle:  57.75973745572647

Never Nesters Beware the following code has the power to make your eyes bleed
'''


img = cv2.imread("standard_test_images/quadrilateral.png", cv2.IMREAD_GRAYSCALE)
rImg = radon(img, np.linspace(0.0, 180.0, num=540, endpoint=False))
rImg = rImg / np.max(rImg)
rImg[rImg < 0.3] = 0
rImg[rImg != 0 ] = 255
kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (3,3))
rImg = cv2.erode(rImg,kernel,iterations = 2)
lines = []

#Getts the polar coordinates from each of the points in the radon transform
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

#Uses the equation (r * cos(theta), r * sin(theta)) to convert the polar coordinates
#to (x,y) coordinates
for i in range(len(lines)):
    coords = (lines[i][0] * np.cos(lines[i][1]), lines[i][0] * np.sin(lines[i][1]))
    slope = np.float32(coords[0] / coords[1]) * -1 # this is the slope of our perpendicular line
    b = (slope * coords[0]  *-1) + coords[1]
    lines[i] = (slope, b)
   
intersects = []

#Calculate the intersections between the 4 lines in our shape
for i in range(len(lines)):
    for k in range(len(lines)):
        if i != k:
            x = (lines[i][1] - lines[k][1]) / (lines[i][0] - lines[k][0])
            y = lines[i][0] * x + lines[i][1]

            ## the intersections between the lines with the same direction of slope are not part of our calculations
            if (lines[i][0] < 0 and lines[k][0] > 0 or (lines[i][0] > 0 and lines[k][0] < 0)):
                duplicate = False
                for j in range(len(intersects)):
                    if(x == intersects[j][0] or y == intersects[j][1]):
                        duplicate = True
                if duplicate == False:
                    intersects.append((x,y))

def findMinIndex(arr, axis):
    min = 0
    for i in range(len(arr)):
        if(arr[i][axis] < arr[min][axis]):
            min = i
    return min
# Place all of the coordinates in an order that we can work with
min = intersects.pop(findMinIndex(intersects,0))
min2 = intersects.pop(findMinIndex(intersects,0))
if(min[1] < min2[1]):
    topLeft = min2
    botLeft = min
else:
    botLeft = min2
    topLeft = min
minY = intersects.pop(findMinIndex(intersects,1))
botRight = minY
topRight = intersects[0]

#Calculate the lenght of each line and the diagonal from the botLeft corner to the topRight corner
def distance(p1,p2):
    return np.sqrt(np.power(p2[0] - p1[0],2) + np.power(p2[1] - p1[1],2))
topLeft_topRight = distance(topLeft,topRight)
topLeft_botLeft = distance(topLeft,botLeft)
topRight_botRight = distance(topRight, botRight)
botLeft_botRight = distance(botLeft,botRight)
diagonal = distance(botLeft,topRight)

def lawOfCosines(a,b,c):
    return np.arccos((c**2 + a**2 - b**2) / (2*a*c))

#solve Triangle 1, the bottom left and top right are going to be the split angles.
c1 = lawOfCosines(diagonal,topLeft_topRight,topLeft_botLeft)
a1 = lawOfCosines(topLeft_topRight,diagonal,topLeft_botLeft)
b1 = lawOfCosines(topLeft_topRight,topLeft_botLeft, diagonal)
c2 = lawOfCosines(diagonal, topRight_botRight, botLeft_botRight)
a2 = lawOfCosines(topRight_botRight,diagonal, botLeft_botRight)
b2 = lawOfCosines(diagonal, botLeft_botRight, topRight_botRight)
topLeftAngle = a1
botLeftAngle = c1 + c2
botRightAngle = a2
topRightAngle = b1 + b2

print("topLeftAngle: ", topLeftAngle * (180/np.pi))
print("botLeftAngle: ", botLeftAngle * (180/np.pi))
print("botRightAngle: ", botRightAngle * (180/np.pi))
print("topRightAngle: ", topRightAngle * (180/np.pi))

cv2.imshow("Quadrilateral", img)
cv2.imshow("Radon Transform", rImg)
cv2.waitKey(0)
cv2.destroyAllWindows()
