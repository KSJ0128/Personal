S = input()
cnt = 0 
check = 0 
s_index = 0
s = 0
e = len(S) - 1

while(s < e):
    if(S[s] == S[e]):
        if(check == 0):
            s_index = s
            check = 1
        e -= 1
        s += 1
    else:
        if(check == 0):
            s += 1
            cnt = s
        else:
            check = 0
            s = s_index + 1
            e = len(S) - 1
        cnt = s
    
print(cnt + len(S))