N = int(input())
nInt = sorted(list(map(int,input().split())))
M = int(input())
mInt = list(map(int,input().split()))

for i in range(N):
    check = 0
    for j in range(M):
        if mInt[i] == nInt[j]:
           check = 1
           break
        elif mInt[i] < nInt[j]:
            break
    print(check)
        