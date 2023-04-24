import numpy as np


def SequenceDetector():
    # inputting arrays using list comprehension, then
    # converting to a numpy array
    array = np.array([int(i) for i in input("Enter elements: ").split()])

    sequence = np.array([int(i) for i in input(
        "Enter sequence to search for: ").split()])

    count = 0

    for i in range(len(array)):
        if(array[i] == sequence[0]):
            j = i + 1
            k = 1
            while(j < len(sequence)):
                if(array[j] == sequence[k]):
                    k += 1
                j += 1
                i += 1
            if(k == len(sequence)-1):
                count += 1

    print(count)


SequenceDetector()
