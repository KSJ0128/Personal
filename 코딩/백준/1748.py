N = int(input())

if N < 10:
    print(N)
elif N < 100:
    print(9+(N-9)*2)
elif N < 1000:
    print(189+(N-99)*3)
elif N < 10000:
    print(2889+(N-999)*4)
elif N < 100000:
    print(38889+(N-9999)*5)
elif N < 1000000:
    print(488889+(N-99999)*6)
elif N < 10000000:
    print(5888889+(N-999999)*7)
elif N < 100000000:
    print(68888889+(N-9999999)*8)
else:
    print(788888898)