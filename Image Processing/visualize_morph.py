import numpy as np
import matplotlib.pyplot as plt

N = 500


# length must be odd
def erode(x, y, length):
    num_points = len(x)
    X = np.copy(x[length // 2:-length // 2])
    Y = np.zeros(num_points - length)
    for i in range(num_points - length):
        Y[i] = np.min(y[i:i + length])
    return X, Y


# length must be odd
def dilate(x, y, length):
    num_points = len(x)
    X = np.copy(x[length // 2:-length // 2])
    Y = np.zeros(num_points - length)
    for i in range(num_points - length):
        Y[i] = np.max(y[i:i + length])
    return X, Y


# length must be odd
def open(x, y, length):
    X, Y = erode(x, y, length)
    return dilate(X, Y, length)


# length must be odd
def close(x, y, length):
    X, Y, = dilate(x, y, length)
    return erode(X, Y, length)


# length must be odd
def tophat(x, y, length):
    X, Y = open(x, y, length)
    return X, y[length - 1:-length - 1] - Y


# length must be odd
def bottomhat(x, y, length):
    X, Y = close(x, y, length)
    return X, Y - y[length - 1:-length - 1]


def plot_erode(f, a, b, length):
    x = np.linspace(a, b, num=N)
    y = f(x)
    plt.plot(x, y)
    l = int(N * length / (b - a))
    if l % 2 == 0:
        l = l + 1
    X, Y = erode(x, y, l)
    plt.plot(X, Y)
    plt.show()


def plot_dilate(f, a, b, length):
    x = np.linspace(a, b, num=N)
    y = f(x)
    plt.plot(x, y)
    l = int(N * length / (b - a))
    if l % 2 == 0:
        l = l + 1
    X, Y = dilate(x, y, l)
    plt.plot(X, Y)
    plt.show()


def plot_open(f, a, b, length):
    x = np.linspace(a, b, num=N)
    y = f(x)
    plt.plot(x, y)
    l = int(N * length / (b - a))
    if l % 2 == 0:
        l = l + 1
    X, Y = open(x, y, l)
    plt.plot(X, Y)
    plt.show()


def plot_close(f, a, b, length):
    x = np.linspace(a, b, num=N)
    y = f(x)
    plt.plot(x, y)
    l = int(N * length / (b - a))
    if l % 2 == 0:
        l = l + 1
    X, Y = close(x, y, l)
    plt.plot(X, Y)
    plt.show()


def plot_tophat(f, a, b, length):
    x = np.linspace(a, b, num=N)
    y = f(x)
    plt.plot(x, y)
    l = int(N * length / (b - a))
    if l % 2 == 0:
        l = l + 1
    X, Y = tophat(x, y, l)
    plt.plot(X, Y)
    plt.show()


def plot_bottomhat(f, a, b, length):
    x = np.linspace(a, b, num=N)
    y = f(x)
    plt.plot(x, y)
    l = int(N * length / (b - a))
    if l % 2 == 0:
        l = l + 1
    X, Y = bottomhat(x, y, l)
    plt.plot(X, Y)
    plt.show()


plot_bottomhat(lambda x: np.sin(2 * x), 0, 20, 2)
