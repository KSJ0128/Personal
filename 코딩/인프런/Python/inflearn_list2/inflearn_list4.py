# 0~10 사이의 짝수에 10을 곱한 값으로 리스트 생성
li1 = [x*10 for x in range(10) if x%2==0] 
print(li1)
print('---------------------------------------------')


# 문장을 단어별로 split해 리스트 생성
words = "hello my name is seojin. i'm working at london steak.".split()


# 단어의 0번째 글자로 리스트 생성
li2 = [x[0] for x in words]
print(li2)
print('---------------------------------------------')


# 단어의 길이로 리스트 생성
li3 = [len(x) for x  in words]
print(li3)
print('---------------------------------------------')


# 각각 color와 car의 리스트 생성
color = ['red', 'blue','black']
car = ['benz', 'bmw', 'ferrari']


# color와 car의 상호곱으로 리스트 생성
li4 = [(x,y) for x in color for y in car] # color의 x와 car의 y를 상호곱
print(li4)
print('---------------------------------------------')


# 정수형 리스트의 최솟값, 최댓값 찾기
number = [10, 23, 26, 6, 64, 84]

min = number[0]
max = number[0]

for x in range(1, len(number)):
    if number[x] < min:
        min = number[x]
    if number[x] > max:
        max = number[x]

print('min: ', min)
print('max: ', max)
print('---------------------------------------------')


# 문자열 리스트의 최솟값, 최댓값 찾기
words = ['apple', 'banana', 'lion', 'tiger', 'car']

min = words[0]
max = words[0]

for x in range(1, len(words)):
    if len(words[x]) < len(min):
        min  = words[x]
    if len(words[x]) > len(max):
        max  = words[x]

print(min)
print(max)
print('---------------------------------------------')


# in, not in & index 활용
words = ['apple', 'banana', 'lion', 'tiger', 'car']

if 'bird' in words:
    print(words.index('tiger'))
else:
    print(words.index('car'))
print('---------------------------------------------')


# 순차 탐색
def linearSearch(li, key): # 탐색 성공시 i를 return, 실패시 -1을 return. 
    for i in range(len(li)):
        if li[i] == key:
            return i       # 탐색 성공시 i return 시키고 반복문 종료 후 함수 종료.
    return -1              # 반복문 종료시까지 탐색 실패시 -1 return하고 함수 종료.

li = [10, 20, 30, 40, 50, 60, 70 ,80 , 90, 100]
key = 70

index = linearSearch(li, key)

if index == -1:
    print('탐색 실패')
else:
    print('탐색 성공')
    print('key의 index: ', index)
print('---------------------------------------------')


# 조건에 맞는 요소들 탐색
def linearSearch(li, new, key): # 탐색 성공시 i를 return, 실패시 -1을 return. 
    for i in range(len(li)):
        if li[i] >= key:
            new.append(li[i])    

li = [10, 20, 30, 40, 50, 60, 70 ,80 , 90, 100]
new = []
key = 70

linearSearch(li, new, key)

print(new)
print('---------------------------------------------')

# 선택 정렬
def selectionSort(list):
    for i in range(len(list)):
        leastValue = list[i]
        leastIndex = i
        for j in range(i+1, len(list)):
            if list[j] < leastValue:
                leastValue = list[j]
                leastIndex = j
        tmp = list[i]
        list[i] = leastValue
        list[leastIndex] = tmp

# __name__ == '__main__': 메인 함수라는 뜻
if __name__ == '__main__':
    list = [7, 4, 11, 9 , 2]
    selectionSort(list)
    print(list)
print('---------------------------------------------')

# 순차 정렬 
list = [ 2, 4, 6, 8, 1, 3, 5, 7, 9]
list.sort(reverse = True)
print(list)

li2 = sorted(list, reverse= True)
print(li2)