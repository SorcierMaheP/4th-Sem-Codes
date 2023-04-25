import numpy as np
  
import numpy as np

# to enter a 2d  numpy matrix
m = int(input("Enter dimension m: "))
n = int(input("Enter dimension n: "))

array = np.array([[int(i) for i in input(
    f"Enter elements of row {j}: ").split()] for j in range(n)])
  
# Calculating mean across Rows
row_mean = np.mean(array, axis=1)
  
for i in range(len(row_mean)):
    print(f"mean of row {i} = ", row_mean[i])

  
  
# Calculating mean across Columns
column_mean = np.mean(array, axis=0)

for i in range(len(column_mean)):
    print(f"mean of column {i} = ", column_mean[i])
