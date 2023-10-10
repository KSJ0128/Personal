N = int(input("방의 크기를 입력해주세요."))
rowSeat, colSeat = 0, 0

arr = [[0 for j in range(N)] for i in range(N)] # 배열 0으로 초기화해 선언 

for i in range(N):
        arr[i] = input() # 배열 값 입력 받기

for i in range(N): # 0~4
    for j in range(N-1): # 0~3
        if arr[i][j] == arr[i][j+1] == '.':
            if j-1 < 0 or arr[i][j-1] == 'X':
                colSeat += 1

for i in range(N): # 0~N
    for j in range(N-1): # 0~N-1
        if arr[j][i] == arr[j+1][i] == '.':
            if j-1 < 0 or arr[j-1][i] == 'X':
                rowSeat += 1
            
print(colSeat, rowSeat)