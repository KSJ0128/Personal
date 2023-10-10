'''
scores = []
print("리스트 초기화 값: ", scores)

# append() 통해 list에 값 추가
scores.append(30)
scores.append("안녕")
scores.append(10.1123)
print("리스트 값: ", scores)
print("리스트 크기: ", len(scores))

scores[1] = 'hello'
# scores[index]은 변수와 동일하다. 데이터 변경. 
print("리스트 값: ", scores)
print("리스트 크기: ", len(scores))


# 리스트 순회해서 출력(첫 번째 방법, for문과 range 활용)
# for문은 list와 궁합이 잘 맞다.
# print(scores[0])
# print(scores[1])
# print(scores[2])

print('------------------------------------')
#range 없으면 len(scores)는 3을 의미해 오류 발생하고, range가 붙어야 0, 1, 2의 튜플을 의미한다.
for i in range(len(scores)):
    print(i, scores[i])


# 리스트 값을 순회해서 바꾸기
print('------------------------------------')
for i in range(len(scores)):
    # scores[i] = '안녕'
    scores[i] = i + 10  # 데이터 변경 10, 11 ,12
    print(i, scores[i])


# 리스트 순회해서 출력(두 번째 방법, 리스트 시퀀스 활용)
# 시퀀스 사용하면 인덱스가 아닌 실제 값을 가져와 출력한다.
print('------------------------------------')
for i in scores:
    # scores[i] = '안녕'
    # scores[i] = i + 10  
    # scores[i]를 활용하는 것은 불가능하다. i로 실제 값인 10, 11, 12가 전달되어 인덱스 범위를 벗어나기 때문이다.
    print(i)


# 사용자로부터 입력을 받아 리스트에 값 저장하는 코드
print('------------------------------------')
nums = []
for i in range(5):
    nums.append(int(input("정수 입력: ")))
print(nums)


# list 클래스(속성(멤버 변수), 기능(멤버 메서드), 생성자)
# 생성자 통한 리스트 생성
print('------------------------------------')
li1 = list() # 매개 변수 없는 생성자 호출 = 붕어빵 틀
print("li: ", li1) # 빈 리스트 생성

li2 = list("안녕") # 한 글자씩 리스트 생성
print("li2: ", li2)

li3 = list(range(0,5,2)) # 0부터 2씩 5까지 -> 0, 2, 4
print("li3: ", li3)


#내장 리스트
print('------------------------------------')
li1 = [12, 12.777, '안녕']
print("li1: ", li1)

li2 = [["서울",10], ["뉴욕", 50], ["파리", 70]]
print("li2: ", li2)
print(li2[2][0]) # li2[2]의 0번째 데이터라는 의미.


# 내장 리스트를 더블 루트로 출력하기  // 리스트의 대괄호가 두 개이기 때문에, 세 개인 경우는..?
print('------------------------------------')
for i in range(len(li2)): # li2는 주소의 주소를 갖고 있다. len(li2) = 3이다. -> 0, 1, 2 // 3회 반복
    for j in range(len(li2[i])): # li2[0], li2[1], li2[2]도 주소값을 지니고 있다. -> 0,1 // 2회 반복?
        print(li2[i][j])
'''