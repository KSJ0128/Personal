# 연락처 관리 프로그램 만들기
# 출력 결과
# 1. 친구 리스트 출력
# 2. 친구 추가
# 3. 친구 삭제
# 4. 이름 변경
# 9. 종료
# 메뉴를 선택하시오: 2
# 이름을 입력하시오: 홍길동

def numPrint():
    print('1. 친구 리스트 출력')
    print('2. 친구 추가')
    print('3. 친구 삭제')
    print('4. 이름 변경')
    print('9. 종료')
    return int(input('메뉴를 선택하시오: '))

def phoneBook(nameList):
    while True:
        num = numPrint()

        if num == 9:
            break

        elif num == 1:
            print(nameList)

        elif num == 2:
            nameList.append(input('이름을 입력하시오: '))

        elif num == 3:
            delName = input('이름을 입력하시오: ')

            if delName in nameList:
                nameList.remove(delName)
            else:
                print(delName, '이라는 이름이 존재하지 않습니다.')

        elif num == 4:
            oldName = input('바꾸고 싶은 이름을 입력하시오: ')

            if oldName in nameList:
                oldIndex = nameList.index(oldName)
                newName = input('바꿀 이름을 입력하시오: ')
                nameList[oldIndex] = newName
            else:
                print(oldName, '이라는 이름이 존재하지 않습니다.')
    
    print('------------------------------------')

nameList = []
phoneBook(nameList)