from math import sin, cos, tan, isclose
n = float(input("Enter the value of angle."))
lhs = cos(n)/((1/cos(n))+tan(n))
rhs = 1-sin(n)
if (isclose(lhs, rhs)):
    print("Identity proved.")
    quit()
print("Identity failed to prove.")
