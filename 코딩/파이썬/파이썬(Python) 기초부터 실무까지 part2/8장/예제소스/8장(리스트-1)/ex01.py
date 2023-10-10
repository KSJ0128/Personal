# 리스트에 대한 실습
# 리스트의 정의 : 대량의 데이터를 저장할 수 있는 공간을 만들어야 하고 이 데이터들을
# 손쉽게 처리할 수 있는 형태의 데이터의 저장 구조를 의미한다.

# 리스트를 선언 및 초기화
scores = []
print("리스트 값: ", scores)

# append() 메서드를 통하여 정수 값을 추가함.
scores.append(30)
print("리스트 값 : ", scores)
# append() 메서드를 통하여 문자열을 추가함.
scores.append("안녕")
print("리스트 값 : ", scores)
# append() 메서드를 통하여 실수를 추가함.
scores.append(10.1123)
print("리스트 값 : ", scores)
print("리스트 크기 : ", len(scores))

# 리스트의 값을 변경해보기
# scores[index]은 변수와 동일하다.(중요)
scores[1] = "hello"
print("리스트 값 : ", scores)
print("리스트 크기 : ", len(scores))

# 리스트 순회해서 출력하기(첫 번째 방법 for 문과 range() 함수 이용)
# for 문은 리스트와 궁합이 잘 맞다.
# print(scores[0])
# print(scores[1])
# print(scores[2])
print("---------------")
for i in range(len(scores)):
    print(i, scores[i])
    
# 리스트의 값을 순회해서 바꾸기
print("---------------")
for i in range(len(scores)):
    # scores[i] = "안녕"
    scores[i] = i + 10
    print(i, scores[i])

# 리스트 순회해서 출력하기(두 번째 방법 for 문과 리스트 시퀀스를 이용)
# 시퀀스를 사용하면 인덱스를 가져오는 것이 아니라, 실제 값을 가져와서 출력함.
# 두 번째 방법을 사용할 때는 인덱스를 잘 생각해야 한다.
print("---------------")
for i in scores:
    # scores[i] = "안녕"
    # 아래와 같이 코드를 작성하면 인덱스가 초과가 되어서 에러를 발생시킨다.
    # IndexError 발생함. 저장할 방이 없는데 어떻게 저장을 해야 되니?
    # scores[i] = i + 10
    print(i)

# 사용자로부터 입력을 받아서 리스트에 값을 저장하는 코드
# print("---------------")
# nums = []
# for i in range(5):
#     nums.append(int(input("정수를 입력하세요 : ")))
# print(nums)

# list 클래스(속성(멤버변수), 기능(멤버메서드), 생성자) 생성자를 이용한 리스트 만들기
li1 = list()   # 매개변수가 없는 생성자를 호출(붕어빵을 만드는 형태)
print("li1 : ", li1)

# 아래와 같이 생성자의 매개변수가 문자열이라면 리스트를 생성할 때 문자 하나하나씩 요소로
# 가지게 된다.
li2 = list("안녕")
print("li2 : ", li2)

li3 = list(range(0, 5, 2))
print("li3 : ", li3)

# 내장리스트에 대한 실습
li1 = [12, 12.777, "안녕"]
print("li1 : ", li1)
print("li1[0] : ", li1[0])
li2 = [["서울", 10], ["뉴욕", 50], ["파리", 70]]
print("li2 : ", li2)
print("li2[0][0] : ", li2[0][0])
print("li2[0][1] : ", li2[0][1])
print("li2[1][0] : ", li2[1][0])
print("li2[1][1] : ", li2[1][1])
print("li2[2][0] : ", li2[2][0])
print("li2[2][1] : ", li2[2][1])

# 내장 리스트를 더블 루프로 출력하기
for i in range(len(li2)):     # li2는 주소의 주소를 가지고 있다.len(li2) = 3이다.
    for j in range(len(li2[i])):  # li2[0],li2[1],li2[2] 도 주소값을 지니고 있다.
        print(li2[i][j])        # 2중 내장리스트는 li[i][j] 은 곧 변수와 동일하다.