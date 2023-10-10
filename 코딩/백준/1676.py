from math import factorial

num = str(factorial(int(input())))
cnt = 0

for i in range(len(num) - 1, -1, -1):
    if num[i] == '0':
        cnt += 1
    else:
        break

print(cnt)