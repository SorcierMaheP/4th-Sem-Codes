import numpy as np
A = np.array([[2, -4, 4], [34, 3, -1], [1, 1, 1]])
B = np.array(([8, 30, 108]))
print("\nA array is:\n", A)
print("\nB array is:\n", B)
X = np.linalg.solve(A, B)
print(f"\nThe values of x, y, z are {X[0]}, {X[1]}, {X[2]}.")
