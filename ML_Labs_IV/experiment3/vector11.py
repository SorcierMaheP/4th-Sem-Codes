import numpy as np

# ok, this is like english at this point
# watch this if any doubts arise : https://www.youtube.com/watch?v=dQw4w9WgXcQ

array = np.array([float(i) for i in input("Enter elements: ").split()])

print("floor-ified array: ", np.floor(array))

print("Ceiling-ified array: ", np.ceil(array))

print("truncated array: ", np.trunc(array))
