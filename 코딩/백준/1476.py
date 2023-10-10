E, S, M = map(int, input().split())
year = 1

while year:
    e = year % 15 if year % 15 != 0 else 15
    s = year % 28 if year % 28 != 0 else 28
    m = year % 19 if year % 19 != 0 else 19

    if e == E and s == S and m == M: # 15 28 19일 땐...
        break
    year += 1

print(year)