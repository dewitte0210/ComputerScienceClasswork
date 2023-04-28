import cv2
import numpy as np
from imutils.object_detection import non_max_suppression

# Confidence threshold for determining whether a region contains a letter
CONFIDENCE = 0.5

image = cv2.imread("images_with_text/tshirt.jfif")[:, :, ::-1]
# Image must have a height and width that is a multiple of 32
# EAST seems to work best with square images
image = cv2.resize(image, (640, 640))
original = np.copy(image[:, :, ::-1])
H,W = image.shape[:2]

# Load in ANN
net = cv2.dnn.readNet("frozen_east_text_detection.pb")

# Confidence and geometry of bounding box layers
layerNames = ["feature_fusion/Conv_7/Sigmoid", "feature_fusion/concat_3"]

# Prepare image for use in ANN
blob = cv2.dnn.blobFromImage(image=image, scalefactor=1.0, size=(W,H), mean=(123.68, 116.78, 103.94),
                             swapRB=True, crop=False)
net.setInput(blob)
# Run ANN on image and return the listed layers
scores, geometry = net.forward(layerNames)

# stored backwards because it was programmed backwards
y, x = np.where(scores[0, 0] > CONFIDENCE)

# unravel geometry information
h_upper, w_right, h_lower, w_left, theta = geometry[0, :, y, x].T

# sine and cosine of the angles of the boxes
c = np.cos(theta)
s = np.sin(theta)

# Height of the box
h = h_upper + h_lower

# Width of the box
w = w_right + w_left

# Fancy Trigonometry
endX = x * 4 + c * w_right + s * h_lower
endY = y * 4 - s * w_right + c * h_lower
startX = endX - w
startY = endY - h

rectangles = np.round(np.stack((startX, startY, endX, endY)).T).astype(dtype=int)
boxes = non_max_suppression(rectangles, probs=scores[0, 0, y, x])

for box in boxes:
    cv2.rectangle(original, (box[0], box[1]), (box[2], box[3]), (255, 0, 0), 2)

cv2.imshow("Boxed", original)
cv2.waitKey(0)
cv2.destroyAllWindows()
