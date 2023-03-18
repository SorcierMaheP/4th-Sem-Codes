def deg():
    deg = float(input("Enter the measure in degrees."))
    print("The radian measure is: ", deg*3.14/180)


def rad():
    rad = float(input("Enter the measure in radians."))
    print("The degree measure is: ", rad*180/3.14)


inp = int(input("Enter 1 for degrees and 2 for radians."))
if (inp == 1):
    deg()
elif (inp == 2):
    rad()
else:
    print("Invalid input.")
