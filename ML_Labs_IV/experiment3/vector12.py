import numpy as np

# to enter a 2d  numpy matrix
m = int(input("Enter dimension m: "))
n = int(input("Enter dimension n: "))

# inputing the 2 matrices 
array1 = np.array([[int(i) for i in input(
    f"Enter elements of row {j} of array 1: ").split()] for j in range(n)])

array2 = np.array([[int(i) for i in input(
    f"Enter elements of row {j} of array 2: ").split()] for j in range(n)])

print("Original matrices: ")
print(array1)
print(array2)

# calcualting Einstein's summation :
einsteinSummation = np.einsum("mk,kn", array1, array2)

print("Enisteins summation of matrices: ")
print(einsteinSummation)
