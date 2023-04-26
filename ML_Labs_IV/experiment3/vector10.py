import numpy as np


array = np.array([int(i) for i in input("Enter elements: ").split()])

# sorting array

array = np.sort(array)

n = int(input("Enter value of n: "))

# printing last n values of sorted array
# hence, the n largest values of array
print(array[-n:])
