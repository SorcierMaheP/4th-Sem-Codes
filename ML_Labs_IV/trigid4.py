from math import sin, cos, isclose, pi
n = int(input("Enter the accuracy of checking."))
for i in range(1, n**2):
    lhs = sin(pi/2-i)
    rhs = cos(i)
    if (not (isclose(lhs, rhs))):
        break
    else:
        if (i == n**2-1):
            print("Identity proved.")
            quit()
print("Identity failed to prove.")
