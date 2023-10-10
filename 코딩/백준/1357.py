X, Y = input().split()
sum = int(''.join(reversed(list(X)))) + int(''.join(reversed(list(Y))))
print(int(''.join(reversed(list(str(sum))))))