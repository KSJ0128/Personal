import sys

N = int(input())
stack = [] #LIFO


for i in range(N):
    command = list(sys.stdin.readline().split())

    if command[0] == "push":
        stack.append(int(command[1]))
    elif command[0] == "pop":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())
    elif command[0] == "size":
        print(len(stack))
    elif command[0] == "empty":
        print(1) if len(stack) == 0 else print(0)
    else:
        print(stack[len(stack)-1]) if len(stack) != 0 else print(-1)