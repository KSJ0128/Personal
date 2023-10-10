import sys

str = list(sys.stdin.readline().split()) # 초기에 입력되어 있는 문자열, 문자열의 길이는 N
M = int(sys.stdin.readline())

cursor = len(str) # == N

for i in range(int(M)):
    cmd = list(sys.stdin.readline().split())

    if cmd[0] == "L": # 커서 왼쪽으로 한 칸
        if cursor == 0:
            pass
        else: 
            cursor -= 1
    elif cmd[0] == "D": # 커서 오른쪽으로 한 칸
        if cursor == len(str):
            pass
        else: 
            cursor += 1
    elif cmd[0] == "B": # 커서 왼쪽 문자 삭제
        if cursor == 0:
            pass
        else:
            cursor -= 1
            str.pop(cursor)
    elif cmd[0] == "P": # 커서 왼쪽에 문자 삽입
        str.insert(cursor, cmd[1])
        cursor += 1

sys.stdout.write(''.join(str))