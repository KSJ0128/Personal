N = int(input())
while True:
    if str(N) == ''.join(reversed(list(str(N)))): # 팰린드롬인 경우
        check = True
        for i in range(2, N): # 소수 체크
            if(N % i == 0): # 소수 아닐 때
                check = False
                break # for문 탈출
        if check == False or N == 1: # 소수 아닌 경우
            N += 1
            continue
        elif check == True: # 소수인 경우
            print(N)
            break
    else: # 팰린드롬 아닌 경우
        N += 1
        continue       