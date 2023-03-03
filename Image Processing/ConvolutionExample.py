import cv2
import numpy as np

img = cv2.imread("standard_test_images/peppers_color.tif", cv2.IMREAD_GRAYSCALE)/255.0
kernel = np.array([[0,1,0],[1,-4,1],[0,1,0]])
#kernel = np.ones(5)/5.0  #Performs a motion blur, it essentially averages a range of 20 pixels for each pixel
#convolved = cv2.filter2D(img,-1,kernel)
G_x = np.array([[1,0,-1],[2,0,-2],[1,0,-1.0]])
G_y = np.array([[1,2,1],[0,0,0],[-1,-2,-1.0]])
convolved = np.sqrt(cv2.filter2D(img, -1,G_x)**2 + cv2.filter2D(img, -1, G_y)**2)
#convolved = (convolved-np.min(convolved))/(np.max(convolved)-np.min(convolved))
convolved[convolved < 0.4] = 0.0
convolved[convolved > 0] = 1
cv2.imshow("Filter", np.concatenate((img, convolved), axis=1))
cv2.waitKey(0)
cv2.destroyAllWindows()
