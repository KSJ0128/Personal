N, M = map(int,input("듣, 보").split())

n = [input() for i in range(N)]
m = [input() for i in range(M)]
name = []

for i in range(N):
    for j in range(M):
        if n[i] == m[j]:
            name.append(n[i])

name.sort()

print(len(name))

for i in range(len(name)):
    print(name[i])