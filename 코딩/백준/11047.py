# 알고리즘
# K보다 작은 동전의 가치 중 가장 큰 값의 나머지를 구한다.
# 나머지 가치보다 작은 동전의 가치 중 가장 큰 값의 나머지를 구한다.
# 반복

N, K = map(int, input().split())
coin, cnt, index = [0]*N, 0, 0

for i in range(N-1, -1, -1): # 제대로 수행
    coin[i] = int(input())
while True: 
    if coin[index] <= K:
        cnt += K // coin[index]
        K = K % coin[index] 
        if K == 0:
            print(cnt)
            break
    index += 1 # -=로 작성해서 틀렸었음
