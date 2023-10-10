T = int(input())

for t in range(T):
    count = 0

    M, N, K = map(int, input().split())
    arr = [[0 for j in range(M)] for i in range(N)] # 배열 0으로 초기화

    for k in range(K):
        m, n = map(int, input().split()) # 열, 행 위치 입력 받기
        arr[n][m] = 1
    # 여기까진 이상 없음

    for i in range(N):
        for j in range(M):
            if arr[i][j] == 1:
                if i > 0 and j < M-1 and arr[i][j+1] == 1 and arr[i-1][j+1] == 1:
                    continue
                elif i > 0 and j > 0 and arr[i-1][j] == arr[i][j-1] == 0:
                    count += 1
                elif i == 0 and j > 0 and arr[i][j-1] == 0:
                    count += 1
                elif i > 0 and j == 0 and arr[i-1][j] == 0:
                    count += 1
                elif i == 0 and j == 0:
                    count += 1

    print(count)