from math import sin, cos, tan, isclose
n = int(input("Enter the accuracy of checking."))
for i in range(n**2):
    lhs = cos(i)/((1/cos(i))+tan(i))
    rhs = 1-sin(i)
    if (not (isclose(lhs, rhs))):
        break
    else:
        if (i == n**2-1):
            print("Identity proved.")
            quit()
print("Identity failed to prove.")
