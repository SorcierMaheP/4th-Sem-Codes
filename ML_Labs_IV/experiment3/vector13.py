import numpy as np


array = np.array([int(i) for i in input("Enter elements: ").split()])

variance = np.var(array)

print("Variance = ", variance)