import pytesseract
from pytesseract import Output
import cv2

pytesseract.pytesseract.tesseract_cmd = 'C:\\Users\\DewittEvan\\AppData\\Local\\Programs\\Tesseract-OCR\\tesseract.exe'

img = cv2.imread("images_with_text/code.png")
imgGray = cv2.imread("images_with_text/code.png", cv2.IMREAD_GRAYSCALE)

imgGray[imgGray < 100] = 0
imgGray[imgGray > 99] = 255
cv2.imshow("adjusted", imgGray)
#print(pytesseract.image_to_string(imgGray, config="--psm 6"))
tData = pytesseract.image_to_data(imgGray, config="--psm 11", output_type=Output.DICT)

CONFIDENCE = 90
numMatches = len(tData["text"])

x, y, w, h = tData["left"], tData["top"], tData["width"], tData["height"]

for i in range(numMatches):
    if tData["conf"][i] > CONFIDENCE:
        cv2.rectangle(img,(x[i], y[i]), (x[i]+w[i], y[i]+h[i]), (0,0,255),2)
        print(tData["text"][i])

cv2.imshow("Boxed", img)
cv2.waitKey(0)
cv2.destroyAllWindows()