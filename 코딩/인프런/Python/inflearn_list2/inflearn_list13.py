# 2차원 리스트 체커보드 형태로 나타내는 실습
# 체커보드 출력
def printList(list):
    for rows in range(len(list)):
        for cols in range(len(list[0])):
            print(list[rows][cols], end = " ") # 끝에 공백 문자 출력
        print() # 줄바꿈 문자

# 체커보드 형태로 수정
def init(list):
    for rows in range(len(list)):
        for cols in range(len(list[0])):
            if (rows+cols) % 2 == 0:
                list[rows][cols] = 1

# 메인 함수
if __name__ == "__main__":
    table = []
    for row in range(5):
       table.append([0] * 5)
    init(table)
    printList(table)
