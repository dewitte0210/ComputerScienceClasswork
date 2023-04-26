import numpy as np
import cv2

with open("classifictaion_classes")

#use the firts listed name for each class
class_names = [name.split(',')[0] for name in image_net_names]

#load in the pretrained neural network
mode = cv2.dnn.readNet(model="bvlc_googlenet.caffemodel", config="Prototext.yml", framework="Caffe")
