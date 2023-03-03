import cv2
import numpy as np

# Read in the file clocktower.jpg
img = cv2.imread("clocktower.jpg", cv2.IMREAD_COLOR)
print(img.shape)

# [start (inclusive) : end (exclusive) : increment]
#1. Display the Mirror Image
##img[::1] = img[::, 1400::-1]

#2 Display only the red channel of the image
##img[::, :: , 0:2:] = 0

#3 Diplay only the upper left 100x100 Pixels
##img = img[:100:, :100:]

#4 Invert all of the colors
##img = 255 - img[:]

#5 Scale the image to 50%
##img = img[::2, ::2]

#6 Darken the image by reducing the intensity
##img[img < 50] = 50
##img = img -50

#7 Brighten the image by increasing the intensity
##img[img > 200] = 200
##img+=50 

#8 Try to figure out what is going on? No clue there broski

#9 Swap the blue and red channels
##img[:,:,0] = img[:,:,2]


# Show image in a window and exit on keypress
cv2.imshow("Read And Show", img)
cv2.waitKey(0)
cv2.destroyAllWindows()