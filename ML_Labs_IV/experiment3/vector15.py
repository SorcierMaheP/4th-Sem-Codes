# Compute pearson product-moment correlation coefficients of two given NumPy arrays
import numpy as np


# inputing the arrays: 
array1 = np.array([int(i) for i in input("Enter elements: ").split()])
array2 = np.array([int(i) for i in input("Enter elements: ").split()])

pearsonProduct = np.corrcoef(array1, array2)

print("Pearson Product-moment= ", pearsonProduct)