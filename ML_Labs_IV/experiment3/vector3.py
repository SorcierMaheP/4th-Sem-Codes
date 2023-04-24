import numpy as np

# to enter a 2d  numpy matrix
m = int(input("Enter dimension m: "))
n = int(input("Enter dimension n: "))

array = np.array([[int(i) for i in input(
    f"Enter elements of row {j}: ").split()] for j in range(n)])

print("original matrix: ", array)

# swapping the axes of the array
# since its a 2d array, its just its
# transpose here :
# alternatively use:
# array = np.transpose(array)

array = np.swapaxes(array, 0, 1)

print("matrix with axes changed : ", array)
