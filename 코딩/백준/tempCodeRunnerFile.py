S = input()
cnt = 0
check = 0
s = 0
e = len(S) - 1

while(s < e):
    if(S[s] == S[e]):
        e -= 1
    else:
        e = len(S) - 1
        cnt = s + 1
    s += 1

print(cnt + len(S))