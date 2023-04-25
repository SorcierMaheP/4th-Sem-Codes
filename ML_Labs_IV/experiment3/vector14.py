import numpy as np


array = np.array([int(i) for i in input("Enter elements: ").split()])

stdDeviation = np.std(array)

print("Standard Deviation = ", stdDeviation)
