from math import sin, tan, isclose
n = int(input("Enter the accuracy of checking."))
for i in range(1, n**2):
    lhs = (1/sin(i))+(1/tan(i))
    rhs = (1/tan(i/2))
    if (not (isclose(lhs, rhs))):
        break
    else:
        if (i == n**2-1):
            print("Identity proved.")
            quit()
print("Identity failed to prove.")
