import numpy as np

# USing list comprehension to create a
# numpy array with all elements set to 1

n = int(input("Enter length: "))
array = np.array([1 for i in range(n)])

print(array)
