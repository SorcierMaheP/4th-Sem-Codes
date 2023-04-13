from math import sin, cos, isclose
n = float(input("Enter the value of angle."))
lhs = ((1/cos(n)+1))/(1/cos(n)**2)
rhs = (sin(n)**2)/((1/cos(n))-1)
if (isclose(lhs, rhs)):
    print("Identity proved.")
    quit()
print("Identity failed to prove.")
