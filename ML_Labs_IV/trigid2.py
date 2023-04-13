from math import sin, tan, isclose
n = float(input("Enter the value of angle."))
lhs = (1/sin(n))+(1/tan(n))
rhs = (1/tan(n/2))
if (isclose(lhs, rhs)):
    print("Identity proved.")
    quit()
print("Identity failed to prove.")
