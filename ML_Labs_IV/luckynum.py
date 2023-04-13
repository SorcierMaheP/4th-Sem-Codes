n = int(input("Enter n."))
arr = [i+1 for i in range(2**n)]
for i in range(1, 2**n//2):
    if arr[i] == 0:
        continue
    num = arr[i]
    count = 0
    for j in range(2**n):
        if arr[j] != 0:
            count += 1
        if (count % num == 0):
            arr[j] = 0
count = 0
for i in range(2**n):
    if arr[i] != 0:
        count = count+1
        if (count <= n):
            print(arr[i], end=" ")
        else:
            break
print()
