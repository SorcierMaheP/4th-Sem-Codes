import numpy as np


def polynomial(x, y):
    print("sum = ", np.polyadd(x, y))
    print("difference = ", np.polysub(x, y))
    print("product = ", np.polymul(x, y))
    print("quotient = ", np.polydiv(x, y))


print(polynomial((1, 2, 3), (1, 2, 3)))
