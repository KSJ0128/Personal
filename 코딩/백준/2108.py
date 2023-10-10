from statistics import *

N = int(input())
integer = [0]*N
for i in range(N):
    integer[i] = int(input())
integer = sorted(integer)
print(round(mean(integer)))
print(median(integer))
try: print(multimode(integer)[1])
except: print(mode(integer))
#print(multimode(integer)[1] if len(multimode(integer)) > 1 else mode(integer))
print(integer[-1]-integer[0])