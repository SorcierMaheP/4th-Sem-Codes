import numpy as np
n = int(input("Enter the number of variables."))
i = 0
print("Enter values in the form a1x + a2y + a3z + a4w + ... = b")
equ = []
while (i < n):
    i = i+1
    temp = np.array([int(i) for i in input(f"Enter equation {i}:").split()])
    equ.append(temp)
A = np.array([equ[:-1] for equ in equ])
B = np.array([equ[-1] for equ in equ])
print()
X = np.linalg.solve(A, B)
print("The solution matrix is :")
print(X)
