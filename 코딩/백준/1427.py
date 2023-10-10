a = list(input())
a.sort(reverse = True)
str = ""
for i in range(len(a)):
    str += a[i]
print(str)

# print("".join(sorted(input(), reverse=True))): 모범 답안