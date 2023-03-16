num = int(input("Enter the number to be checked."))
sum = 0
for i in range(1, (num//2)+1):
    if (num % i == 0):
        sum += i
if (sum > i):
    print("The number is an abundant number.")
else:
    print("The number is not an abundant number.")
