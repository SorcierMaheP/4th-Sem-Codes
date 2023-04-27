import cmath
a, b, c = map(int, input("Enter the values of a,b,c.").split())
discr = (b**2) - (4*a*c)

root1 = ((-b) + cmath.sqrt(discr)) / (2 * a)
root2 = ((-b) - cmath.sqrt(discr)) / (2 * a)

print('The roots are')
print(root1)
print(root2)
