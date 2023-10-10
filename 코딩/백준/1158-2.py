import sys

N, K = map(int, sys.stdin.readline().split()) # N, K 입력
stack = []

for i in range(1, N+1): # 스택 생성
    stack.append(i)

index = K-1 
yose = []

for i in range(N): # 요세푸스 순열 생성
    yose.append(stack.pop(index)) # 스택에서 pop한 데이터를 yose로 append. stack의 index는 += 1 되는 개념.
    # 1 2 3 4 5 6 7
    # 7, 3

    index += K-1

    while len(stack)-1 < index: # index range issue
        if len(stack) == 1:
            yose.append(stack.pop())
            break
        index -= len(stack)

for i in range(0, N):
    if i == 0:
        sys.stdout.write(f"<{yose[i]}")
    elif i == N-1:
        sys.stdout.write(f", {yose[i]}>")
    else:
        sys.stdout.write(f", {yose[i]}")
    