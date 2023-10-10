# 원하는 행의 합계 구하는 실습
doubleList = [[1,2,3,4,5], [6,7,8,9,10], [11,12,13,14,15]]
sum = 0

for i in range(len(doubleList[0])):
    sum += doubleList[0][i]
print('0행의 합계: ', sum)
print('---------------------------------')

# 2차원 리스트 전체의 합계 구하는 실습
doubleList = [[1,2,3,4,5], [6,7,8,9,10], [11,12,13,14,15]]
sum = 0

for i in range(len(doubleList)):
    for j in range(len(doubleList[0])):
        sum += doubleList[i][j]
print(sum)

# 행별 합계 구하는 실습

doubleList = [[1,2,3,4,5], [6,7,8,9,10], [11,12,13,14,15]]
sum = []

for i in range(len(doubleList)):
    sum.append(0)
    for j in range(len(doubleList[0])):
        sum[i] += doubleList[i][j]
print(sum)
print('---------------------------------')