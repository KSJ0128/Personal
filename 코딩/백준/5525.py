N = int(input()) # P의 길이
M = int(input()) # 문자열의 길이
S = input() # 문자열
P = "IOI"

while(S.find(P) != -1):
    P += "OI"

P_LEN = (len(P) - 1) // 2
print(P_LEN - N + 1)