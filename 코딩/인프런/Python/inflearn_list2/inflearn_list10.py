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

print('---------------------------------------------')

# 순차 정렬 
list = [ 2, 4, 6, 8, 1, 3, 5, 7, 9]
list.sort(reverse = True)
print(list)

li2 = sorted(list, reverse= True)
print(li2)
print('---------------------------------------------')

# 버블 정렬: 큰쪽부터 정렬됨 
def bubbleSort(li):
    listLength = len(li)
    for i in range(listLength-1): # n-1번 반복
        for j in range(listLength-i-1):
            if li[j] > li[j+1]:
                li[j], li[j+1] = li[j+1], li[j]
print('---------------------------------------------')

# __name__ == '__main__': 메인 함수라는 뜻
if __name__ == '__main__':
    list = [7, 4, 11, 9 , 2]
    selectionSort(list)
    print(list)
    print('---------------------------------------------')
    list = [7, 4, 11, 9 , 2]
    bubbleSort(list)
    print(list)
