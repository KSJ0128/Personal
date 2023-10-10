import sys
N, K = map(int,input().split())
num = [0] * N
jose = [] # 요세푸스 순열
joseCnt = 0 # 요세푸스 카운트
cnt = 1 # K 카운트
index = 0 # K 인덱스

while True:
    if index == N-1:
        index = 0
        if num[index] == 0:
            cnt += 1
            if cnt == K:
                cnt = 0
                num[index] = 1
                jose.append(index+1)
                joseCnt += 1
                if joseCnt == N:
                    break
        else:
            pass
    else:
        index += 1
        if num[index] == 0:
            cnt += 1
            if cnt == K:
                cnt = 0
                num[index] = 1
                jose.append(index+1)
                joseCnt += 1
                if joseCnt == N:
                    break
        else:
            pass

for i in range(N):
    if i == 0:
        sys.stdout.write(f"<{jose[i]}")
    elif i == N-1:
        sys.stdout.write(f", {jose[i]}>")
    else:
        sys.stdout.write(f", {jose[i]}")