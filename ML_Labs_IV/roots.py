a, b, c = list(map(int, input(
    "Enter the coefficients of the x^2,x and constant term.").split()))
x1 = ((-1*b)+((b**2)-(4*a*c))**0.5)/(2*a)
x2 = ((-1*b)-((b**2)-(4*a*c))**0.5)/(2*a)
print("The roots of the equation are: ", x1, x2)
