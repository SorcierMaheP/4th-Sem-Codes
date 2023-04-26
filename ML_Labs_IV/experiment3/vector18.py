import numpy as np

array = np.array([int(i) for i in input("Enter elements: ").split()])

file = open("./file.txt", "+w")

for i in array:
    file.write(str(i) + "\n")

file.close()
