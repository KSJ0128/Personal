# 사용자로부터 키를 입력 받아 키값 이상의 값들을 출력하고 그 개수를 구하는 프로그램.

numList = [ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
valueList = []

key = int(input('키를 입력해주세요: '))

for i in range(len(numList)):
    if numList[i] >= key:
        valueList.append(numList[i])

print('키 값 이상의 값: ', valueList)
print('키 값 이상인 값의 개수: ', len(valueList))
