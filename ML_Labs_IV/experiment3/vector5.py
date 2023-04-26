import numpy as np

# this doesnt really need comments 
# you're smart enough to figure it out 
# by this point 

array = np.array([int(i) for i in input("Enter elements: ").split()])

array = np.flip(array)

print(array)
