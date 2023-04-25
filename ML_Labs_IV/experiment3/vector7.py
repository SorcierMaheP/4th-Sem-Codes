import numpy as np

# to filter out even elements

array = [int(i) for i in input("Enter elements: ").split()]

# using the np.extract() function :
# the np.mod creates an array of true or false
# values, the same shape as the original array
# based on the condition
# visit https://numpy.org/doc/stable/reference/generated/numpy.extract.html for more info

array = np.extract(np.mod(array, 2) != 0, array)

print(array)
