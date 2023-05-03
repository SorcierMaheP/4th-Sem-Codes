import numpy as np
import math
import matplotlib.pyplot as plt


def SequenceDetector():
    # inputing arrays using list comprehension, then
    # converting to a numpy array
    array = np.array([int(i) for i in input("Enter elements: ").split()])

    sequence = np.array([int(i) for i in input(
        "Enter sequence to search for: ").split()])

    count = 0

    for i in range(len(array)):
        if (array[i] == sequence[0]):
            j = i + 1
            k = 1
            while (j < len(sequence)):
                if (array[j] == sequence[k]):
                    k += 1
                j += 1
                i += 1
            if (k == len(sequence)-1):
                count += 1

    print(count)


def polynomial(x, y):
    print("sum = ", np.polyadd(x, y))
    print("difference = ", np.polysub(x, y))
    print("product = ", np.polymul(x, y))
    print("quotient = ", np.polydiv(x, y))


print("1: Create a Numpy array filled with all ones.")
print("2: Find the number of occurrences of a sequence in a NumPy array")
print("3: Interchange two axes of an array")
print("4: Trim the leading and/or trailing zeros from a 1-D array")
print("5: Reverse a numpy array")
print("6: make a NumPy array read-only.")
print("7: Replace NumPy array elements that doesn't satisfy the given condition")
print("8: Remove columns in Numpy array that contains non-numeric values")
print("9: Create a Numpy array with random values")
print("10: Get the n-largest values of an array using NumPy.")
print("11: Get the floor, ceiling and truncated values of the elements of a numpy array")
print("12: Evaluate Einstein's summation convention of two multidimensional NumPy arrays")
print("13: Compute the variance of the NumPy array")
print("14: Compute the standard deviation of the NumPy array")
print("15: Compute pearson product-moment correlation coefficients of two given NumPy arrays")
print("16: Calculate the mean across dimension in a 2D NumPy array")
print("17: Define a polynomial function. Add, subtract, multiply and divide one polynomial to another using NumPy")
print("18: Save a NumPy array to a text file?")
print("19: Load data from a text file")
print("20: Plot line graph from NumPy array")
print("21: Create Histogram using NumPy")
print("0:Exit.")
while (1):
    choice = int(input("Enter choice."))
    match choice:
        case 1:
            n = int(input("Enter length: "))
            array = np.array([1]*n)
            print(array)
        case 2:
            SequenceDetector()
        case 3:
            m = int(input("Enter dimension m: "))
            n = int(input("Enter dimension n: "))

            array = np.array([[int(i) for i in input(
                f"Enter elements of row {j}: ").split()] for j in range(m)])

            print("original matrix: ", array)
            array = np.swapaxes(array, 0, 1)

            print("matrix with axes changed : ", array)
        case 4:
            array = np.array([int(i)
                             for i in input("Enter elements: ").split()])

            array = np.trim_zeros(array)

            print(array)
        case 5:
            array = np.array([int(i)
                             for i in input("Enter elements: ").split()])

            array = np.flip(array)

            print(array)
        case 6:
            array = np.array([int(i)
                             for i in input("Enter elements: ").split()])

            array.flags.writeable = False
            array[0] = 2
        case 7:
            array = np.array([int(i)
                             for i in input("Enter elements: ").split()])
            print("if element is not divisible by 2 replace it by 0")
            array[array % 2 != 0] = 0
            print(array)
        case 8:
            array = [[math.nan, 2, 3], [math.nan, 3, 4]]

            # inputing the 2 matrices
            array = np.array(array)

            print("Given array:")
            print(array)

            print("\nRemove all columns containing non-numeric elements ")
            print(array[:, ~np.isnan(array).any(axis=0)])
        case 9:
            n = int(input("Enter size of array."))
            array = np.random.rand(1, n)
            print(array)
        case 10:
            array = np.array([int(i)
                             for i in input("Enter elements: ").split()])
            array = np.sort(array)
            n = int(input("Enter value of n: "))
            print(array[-n:])
        case 11:
            array = np.array([float(i)
                             for i in input("Enter elements: ").split()])

            print("floor-ified array: ", np.floor(array))

            print("Ceiling-ified array: ", np.ceil(array))

            print("truncated array: ", np.trunc(array))
        case 12:
            # to enter a 2d  numpy matrix
            m = int(input("Enter dimension m: "))
            n = int(input("Enter dimension n: "))

            # inputing the 2 matrices
            array1 = np.array([[int(i) for i in input(
                f"Enter elements of row {j} of array 1: ").split()] for j in range(m)])

            array2 = np.array([[int(i) for i in input(
                f"Enter elements of row {j} of array 2: ").split()] for j in range(m)])

            print("Original matrices: ")
            print(array1)
            print(array2)

            # calcualting Einstein's summation :
            einsteinSummation = np.einsum("mk,kn", array1, array2)

            print("Enisteins summation of matrices: ")
            print(einsteinSummation)
        case 13:
            array = np.array([int(i)
                             for i in input("Enter elements: ").split()])
            variance = np.var(array)
            print("Variance = ", variance)
        case 14:
            array = np.array([int(i)
                             for i in input("Enter elements: ").split()])
            stdDeviation = np.std(array)
            print("Standard Deviation = ", stdDeviation)
        case 15:
            array1 = np.array([int(i)
                              for i in input("Enter elements: ").split()])
            array2 = np.array([int(i)
                              for i in input("Enter elements: ").split()])

            pearsonProduct = np.corrcoef(array1, array2)

            print("Pearson Product-moment= ", pearsonProduct)
        case 16:
            m = int(input("Enter dimension m: "))
            n = int(input("Enter dimension n: "))

            array = np.array([[int(i) for i in input(
                f"Enter elements of row {j}: ").split()] for j in range(m)])

            # Calculating mean across Rows
            row_mean = np.mean(array, axis=1)

            for i in range(len(row_mean)):
                print(f"mean of row {i} = ", row_mean[i])

            # Calculating mean across Columns
            column_mean = np.mean(array, axis=0)

            for i in range(len(column_mean)):
                print(f"mean of column {i} = ", column_mean[i])
        case 17:
            array1 = np.array([int(i)
                               for i in input("Enter poly1: ").split()])
            array2 = np.array([int(i)
                               for i in input("Enter poly2: ").split()])
            polynomial(array1, array2)
        case 18:
            array = np.array([int(i)
                             for i in input("Enter elements: ").split()])

            file = open("./Lab Submissions/file.txt", "+w")

            for i in array:
                file.write(str(i) + "\n")

            file.close()
        case 19:
            array = np.loadtxt("./Lab Submissions/file.txt")
            print(array)
        case 20:

            x = np.array([int(i)
                          for i in input("Enter x elements: ").split()])
            y = np.array([int(i)
                          for i in input("Enter y elements: ").split()])

            plt.title("Line graph")
            plt.xlabel("X axis")
            plt.ylabel("Y axis")
            plt.plot(x, y, color="red")
            plt.show()
        case 21:

            a = np.random.randint(100, size=(50))
            bins = np.array([int(i)
                             for i in input("Enter bins value: ").split()])
            np.histogram(a, bins)
            hist, bins = np.histogram(a, bins)
            # printing histogram
            print()
            print(hist)
            print(bins)
            fig = plt.figure(figsize=(10, 7))
            plt.hist(a, bins)
            plt.title("Numpy Histogram")
            plt.show()
            print()
        case 0:
            quit()
