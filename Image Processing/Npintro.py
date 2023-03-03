
import numpy as np

## ADDING ARRAYS AND SINGLE DEMENSION SLICING
"""""
myArray = np.array([2,3,4], dtype = np.float64)
arrayTwo = np.array([5,6,7], dtype = np.float64)
print(myArray + arrayTwo)
print(myArray * arrayTwo)
print(myArray/arrayTwo)
print(myArray[5:0:-1])
print(myArray[:] + myArray[::-1])
"""

## TWO DIMMENSIONAL SLICING
""""
arrayThree = np.array([[1,2,3,4,5,6],[20,21,22,23,24,25],[-1,-2,-3,-4,-5,-6]])
print(arrayThree[:])
print(arrayThree[:,:3])
print(arrayThree[1,2:4])
print(arrayThree[:2,3:5])
print(arrayThree[::2,1::2])
print(arrayThree[:, ::-1])
print(arrayThree[1])
"""
