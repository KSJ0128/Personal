T = int(input())

for i in range(T):
    A, B = map(int, input().split()) # 두 수 입력 받기
    if A < B: # A, B 정렬
        A, B = B, A

    if A % B == 0: # 배수 관계일 때
        print(A)
        continue
    else: # 배수 관계가 아닐 때
        gcf = 1
        for i in range(2, B): # 최대공약수 구하기
            if A % i == 0 and B % i == 0:
                gcf = i
        if gcf == 1:
            print(A*B)
        else:
            print(A*B//gcf)