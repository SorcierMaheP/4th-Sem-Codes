from math import sin, cos, isclose
n = int(input("Enter the accuracy of checking."))
for i in range(1, n**2):
    lhs = ((1/cos(i)+1))/(1/cos(i)**2)
    rhs = (sin(i)**2)/((1/cos(i))-1)
    if (not (isclose(lhs, rhs))):
        break
    else:
        if (i == n**2-1):
            print("Identity proved.")
            quit()
print("Identity failed to prove.")
