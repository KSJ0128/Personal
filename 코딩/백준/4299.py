sum, sub = map(int, input().split())
if sum >= sub and (sum+sub)%2 == 0 and (sum-sub)%2 == 0:
    print((sum+sub)//2, (sum-sub)//2)
else:
    print(-1)