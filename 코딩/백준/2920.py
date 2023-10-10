num = list(map(int, input().split())) # 8개의 정수 입력 받기
check = 0 # ascending, descending, mixed 판별용

if num[0] == 8:
    for i in range(1,8):
        if num[i] != num[i-1] - 1: # descending 규칙에 어긋날 경우
            check = 1
            break
    print("descending") if check == 0 else print("mixed")
elif num[0] == 1:
    for i in range(1,8):
        if num[i] != num[i-1] + 1: # ascending 규칙에 어긋날 경우
            check = 1
            break
    print("ascending") if check == 0 else print("mixed")
else:
    print("mixed")