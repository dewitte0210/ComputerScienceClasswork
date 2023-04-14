import numpy as np


def get_basis(N=8):
    basis = np.zeros((N, N, N, N), dtype=np.double)
    values = (np.arange(N) + 0.5) * np.pi / N
    for i in range(N):
        for j in range(N):
            basis[i, j] = np.cos(values * i)[:, None] * np.cos(values * j)[None, :]
    return basis / N


def get_basis_image(N=8):
    basis = get_basis(N)
    basis -= np.min(basis)
    basis /= np.max(basis)
    b_images = np.zeros(((N + 1) * N + 1, (N + 1) * N + 1, 3), dtype=np.double)
    b_images[:, :, 2] = 1.0
    for row in range(N):
        for col in range(N):
            b_images[row * N + row + 1:(row + 1) * N + row + 1,
            col * N + col + 1:(col + 1) * N + col + 1, :] = basis[row, col, :, :, None]
    return b_images


def get_transformed(image, N=8):
    image = image[:N, :N]
    basis = get_basis(N)
    weights = basis * image
    weights.shape = (N, N, N ** 2)
    weights = weights.sum(axis=-1)
    basis.shape = (N * N, N * N)
    weights.shape = (N * N, 1)
    basis = basis * weights
    basis -= np.min(basis)
    basis /= np.max(basis)
    basis.shape = (N, N, N, N)
    b_images = np.zeros(((N + 1) * N + 1, (N + 1) * N + 1, 3), dtype=np.double)
    b_images[:, :, 2] = 1.0
    for row in range(N):
        for col in range(N):
            b_images[row * N + row + 1:(row + 1) * N + row + 1,
            col * N + col + 1:(col + 1) * N + col + 1, :] = basis[row, col, :, :, None]
    return b_images
