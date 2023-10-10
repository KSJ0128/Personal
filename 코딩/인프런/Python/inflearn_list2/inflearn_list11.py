# 2차원 리스트 실습
# 3행 5열의 2차원 리스트
doubleList = [[1,2,3,4,5], [6,7,8,9,10], [11,12,13,14,15]]

# 해당하는 리스트의 주소값을 출력해보기
print(id(doubleList))
print(id(doubleList[0]), doubleList[0])
print(id(doubleList[1]), doubleList[1])
print(id(doubleList[2]), doubleList[2])

# 2차원 리스트 출력하려면 반드시 더블 루프 필요.
for  i in range(len(doubleList)):
    for j in range(len(doubleList[0])):
        print(doubleList[i][j])

# 2차원 리스트는 동적으로 생성하는 경우가 더 많다.
rows = int(input('원하는 행 입력하세요: '))
cols = int(input('원하는 열 입력하세요: '))
dbl_list = []
for row in range(rows):
    dbl_list += [[0] * cols]
print(dbl_list)
print('----------------------------------------')

# 리스트 함축 이용.
dbl_list = [ ([0] * cols) for row in range(rows)]
print(dbl_list)

#  1차원 리스트에서 list[0] = 변수                                          
# 2차원 리스트에서 list2[1][1] 값이 변수와 동일.
li1  = [1,2,3]
li1[0] = 10
print(li1)

li2 = [[1,2], [3,4]]
li2[0][1] = -7
print(li2)
