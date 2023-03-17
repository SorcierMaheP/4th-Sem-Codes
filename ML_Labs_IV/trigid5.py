from math import sin, cos, isclose, pi, sqrt
n = int(input("Enter the accuracy of checking."))
for i in range(1, n**2):
    lhs = cos(i)+sin(i)
    rhs = sqrt(2)*sin(i+pi/4)
    if (not (isclose(lhs, rhs))):
        break
    else:
        if (i == n**2-1):
            print("Identity proved.")
            quit()
print("Identity failed to prove.")
