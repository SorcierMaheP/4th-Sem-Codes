from math import sin, cos, isclose, pi
n = float(input("Enter the value of angle."))
lhs = sin(pi/2-n)
rhs = cos(n)
print(lhs)
print(rhs)
if (isclose(lhs, rhs)):
    print("Identity proved.")
    quit()
print("Identity failed to prove.")
