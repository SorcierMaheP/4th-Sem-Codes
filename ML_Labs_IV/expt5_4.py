import cmath
a, b, c = 1, 2, 7
print(f"Values of a, b, c are {a}, {b}, {c}.")
discr = (b**2) - (4*a*c)

root1 = ((-b) + cmath.sqrt(discr)) / (2 * a)
root2 = ((-b) - cmath.sqrt(discr)) / (2 * a)

print('The roots are')
print(root1)
print(root2)
