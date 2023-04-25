from math import sin, cos, isclose, pi, sqrt
n = float(input("Enter the value of angle."))
lhs = cos(n)+sin(n)
rhs = sqrt(2)*sin(n+pi/4)
print(lhs)
print(rhs)
if (isclose(lhs, rhs)):
    print("Identity proved.")
    quit()
print("Identity failed to prove.")
