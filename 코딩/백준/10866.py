import sys

N = int(input())
deck = []

for i in range(N):
    command = list(sys.stdin.readline().split())
    
    if command[0] == "push_front":
        deck.insert(0, command[1])
    elif command[0] == "push_back":
        deck.append(command[1])
    elif command[0] == "pop_front":
        if len(deck) == 0:
            print(-1)
        else:
            print(deck.pop(0))
    elif command[0] == "pop_back":
        if len(deck) == 0:
            print(-1)
        else:   
            print(deck.pop(-1))
    elif command[0] == "size":
        print(len(deck))
    elif command[0] == "empty":
        if len(deck) == 0:
            print(1)
        else:
            print(0)
    elif command[0] == "front":
        if len(deck) == 0:
            print(-1)
        else:
            print(deck[0])
    elif command[0] == "back":
        if len(deck) == 0:
            print(-1)
        else:
            print(deck[-1])