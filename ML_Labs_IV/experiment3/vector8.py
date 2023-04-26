# Importing Numpy module
import numpy as np

# Creating 3X3 2-D Numpy array
n_arr = np.array([[10.5, 22.5, 10.5],
                  [41, 52.5, 25],
                  [100, np.nan, 41]])

print("Given array:")
print(n_arr)

print("\nRemove all columns containing non-numeric elements ")
print(n_arr[:, ~np.isnan(n_arr).any(axis=0)])
