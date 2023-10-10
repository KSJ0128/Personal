K = int(input())

for i in range(K):
    score = sorted(list(map(int,input().split()[1:])), reverse=True)
    gap = 0
    for j in range(len(score)-1):
        if gap < score[j]-score[j+1]:
            gap = score[j]-score[j+1]
    print(f"Class {i+1}\nMax {score[0]}, Min {score[len(score)-1]}, Largest gap {gap}")