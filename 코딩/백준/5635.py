# 런타임 에러 이유: input을 한 줄에 받아야함.
n = int(input()) # 학생 수 입력 받기

# 변수 초기화
name, dd, mm, yyyy = [0]*n, [0]*n, [0]*n, [0]*n
minName, maxName, minD, minM, minY, maxD, maxM, maxY = "","",0,0,0,0,0,0

for i in range(0,n): # n번 반복
    name[i], dd[i], mm[i], yyyy[i] = input().split()
    dd[i] = int(dd[i])
    mm[i] = int(mm[i])
    yyyy[i] = int(yyyy[i])
    if i == 0:
        minName, maxName, minD, minM, minY, maxD, maxM, maxY = name[0], name[0], dd[0], mm[0], yyyy[0], dd[0], mm[0], yyyy[0]
    elif maxY >= yyyy[i]: # 나이 많은 case
        if maxY > yyyy[i]:
            maxName = name[i]
            maxY = yyyy[i]
            maxM = mm[i]
            maxD = dd[i]
        elif maxM >= mm[i]:
            if maxM > mm[i]:
                maxName = name[i]
                maxY = yyyy[i]
                maxM = mm[i]
                maxD = dd[i]
            elif maxD > dd[i]:
                maxName = name[i]
                maxY = yyyy[i]
                maxM = mm[i]
                maxD = dd[i]
    elif minY <= yyyy[i]: # 나이 적은 case
        if minY < yyyy[i]:
            minName = name[i]
            minY = yyyy[i]
            minM = mm[i]
            minD = dd[i]
        elif minM <= mm[i]:
            if minM < mm[i]:
                minName = name[i]
                minY = yyyy[i]
                minM = mm[i]
                minD = dd[i]
            elif minD < dd[i]:
                minName = name[i]
                minY = yyyy[i]
                minM = mm[i]
                minD = dd[i]
    else: # 해당 x
        pass
print(minName)
print(maxName)