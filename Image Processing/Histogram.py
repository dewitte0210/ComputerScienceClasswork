import numpy as np
import cv2
from matplotlib import pyplot as plt

"""
Creates an equalized version of the image. See equalized.pdf posted to D2L
for details on the mathematics and motivation behind the algorithm.
"""
def equalize_histogram(image):
    """
    :param image: The input image (assumed to be grayscale)
    :return: The equalized image
    """
    """
    The numpy method histogram has quite a few different parameters. The first
    parameter that we are passing is the actual grayscale image. It will be from
    this array that numpy computes the frequencies.
    
    The next parameter is specifying an array of bins. arange is the numpy
    version of range. A few words of caution here because the number 257 might
    seem out of place. When using np.arange(number) it will give you an array
    from 0 to that number incremented by one (there are variations to get any
    start, stop, and increment that you want). As we have previously seen in
    Python the upper bound is strict, that is np.arange(4) would give the array
    [0, 1, 2, 3]
    and 4 would be excluded. Therefore np.arange(257) would give the array
    [0, 1, ..., 256].
    
    We have to understand how histogram works to see why we want to go to 256
    when our images will only have values from 0 to 255. It turns out that
    numpy histograms use half closed/half open intervals, with the exception
    of the last which is closed on both ends. For example, if we used
    [0, 1, 2, 3] for our bins parameter, then the actual bins would be:
    [0, 1), [1, 2), [2, 3]
    
    Therefore, if we were to pass [0, 1, ..., 255] as our bins, we would end up
    with actual bins:
    [0, 1), ..., [253, 254), [254, 255]
    and pixels of intensity 254 and 255 would be effectively merged into the same
    bin. Thus we have to use [0, 1, ..., 256] as our bin dividers to end up with
    256 bins with each intensity being stored in a separate bin.
    
    Finally, the last parameter we are passing is density=True. By default
    numpy will return the actual number of pixels in each bin. We want the
    proportion of pixels in each bin. The density=True parameter gives us
    the desired output.
    
    If you notice there is a [0] on the end. This is because np.histogram
    returns an array of two arrays. The first is the frequency information
    that we want. The second is just the list of bins. As we have explicitly
    stated our bins and we no longer need that list, we just want the first
    element of the array, which is the frequency information. 
    """
    histogram = np.histogram(image, bins=np.arange(257), density=True)[0]
    """
    The numpy method cumsum is the Cumulative Sum of the array passed so it. This
    is our discrete version of integration. In other words if the original array 
was:
    [2, 3, 1, 4, 2]
    Then cumsum would return
    [2, 5, 6, 10, 12]
    the i-th entry in the new array is the sum of the 0-th through i-th entries
    in the original array. 
    """
    cdf = np.cumsum(histogram)
    """
    The multiplication by 255 is being broadcast through the cdf array. This is to
    scale our intensities so that they go from 0 to 255 rather than 0 to 1. See
    the equalized.pdf file online for a further explanation of why. Finally we have
    to get these intensities into uint8. We use the numpy command round and then 
cast
    the result so that we have an array of the proper data type.
    
    We can think of intensities now as a lookup table. If you were to pass it a 10,
it
    would give you the new intensity of any pixel that originally had intensity 10.
    """
    intensities = np.uint8(np.round(255.*cdf))
    """
    This is sometimes referred to as 'fancy indexing.' The output is going to be an
    array with the same shape as image, and of the same type as intensities. We 
need
    image to be an integer type array (uint8 suffices). This type of indexing will
    replace each intensity in image with the new intensity.
    
    As an example (obviously not of full size) consider
    intensities = np.array([5, 4, 2, 9], dtype=np.uint8)
    and
    image = np.array([[0, 2], [1, 4]], dtype=np.uint8)
    Then
    intensities[image] would be the array
    [[5, 2],
     [4, 9]]
     
    If you think about it, this is not far off from how normal array indexing 
works.
    Just instead of accessing a single element at a time, we are accessing an 
entire
    array worth of elements.
    """
    return intensities[image]
    
def main():
    image = cv2.imread("washed_out_images/trees.jpg", cv2.IMREAD_GRAYSCALE)
    # Display the histogram of the image
    plt.hist(image.ravel(), 64, [0, 256])
    plt.show()
    #148 - 156 Equalizing Historgrams
    histogram = np.histogram(image, bins=np.arange(257), density=true)
if __name__ == "__main__":
    main()