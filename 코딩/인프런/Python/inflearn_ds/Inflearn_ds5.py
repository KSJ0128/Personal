# 튜플(tuple): 리스트와 달리 변경이 불가능. 시퀀스의 일종. 속도가 빠르다.
# +, *, min(), max(), len(), cmp(), tuple() 등 내장 함수 사용 가능.
# 리스트: [], 튜플: ()

colors = ['red', 'yellow', 'blue']
print(colors)
print(type(colors))
print('---------------------------------')

numbers = (1,2,3,4,5)
print(numbers)
print(type(numbers))
print('---------------------------------')

# 튜플도 리스트와 같이 여러 자료형 혼합 가능.
tuple1 = (1, 2.2, '하이')
print(tuple1)
print('---------------------------------')

# 공백 튜플 만들기
tuple2 = () # 수정이 불가해 사실상 의미X

# tuple2[0] = 100: 튜플은 한 번 생성되면 수정 불가.

tuple3 = (10,) # 요소가 한 개인 경우 ,를 사용해야 튜플로 정의됨.
print(tuple3)
print('---------------------------------')

# tuple()을 통해 리스트를 튜플로 정의 가능.
li = [1,2,3,4,5]
tuple4 = tuple(li)
print(li)
print(tuple4)
print('---------------------------------')

# 튜플도 리스트와 마찬가지로 내장 튜플 가질 수 있다,
t1 = (1, 2.2, '반가워요')
t2 = (3.3, 4.4, 5.5)
print(t2)
print(type(t2))
print('---------------------------------')

t3 = t1, t2 
t4 = t1 + t2
print('t1의 주소: ', id(t1))
print('t2의 주소: ', id(t2))
print('t3의 주소: ', id(t3))
print('t4의 주소: ', id(t4))
print('---------------------------------')

print('t3[0]의 주소: ', id(t3[0])) # t1 주소와 같다
print('t3[1]의 주소: ', id(t3[1])) # t2 주소와 같다
print('t4[0]의 주소: ', id(t4[0])) # t1 주소와 다르다
print('t4[1]의 주소: ', id(t4[1])) # t2 주소와 같다
print(t3)
print(t4)
print('---------------------------------')

t4 = (1,2,3,'안녕')
t5 = (1, 2.2, 3)
print('t4의 길이: ', len(t4)) 

# 서로 다른 데이터 타입이 튜플 요소라면 비교 불가.
print('t5의 가장 큰 값: ', max(t5))
print('t5의 가장 큰 값: ', min(t5))
print('---------------------------------')

t6 = (1, 2.2, 3, '안녕')
t7 = (1, 2.2, 3)
t8 = t6 + t7 # + 통해 튜플 접합 가능
print(t8)

t9 = t7*2
print(t9)
print('---------------------------------')

if 2.2 in t6:
    print('t6에는 2.2가 존재합니다.')

# 튜플은 시퀀스의 일종이라 반복 가능.
for x in t6:
    print(x, end = " ")
print()
print('---------------------------------')

# 인덱싱
t10 = (1, 2.2, 3, '안녕', '철수', 5.5)
print(t10[4])
print(t10[-1])
print(t10[:])
print('---------------------------------')

# 슬라이싱
print(t10[4:6])
print(t10[-3:-1]) # 튜플은 음수 인덱스 슬라이싱시 절댓값 큰 게 앞으로
print('---------------------------------')

# cmp() 함수는 지원X
t1 = (1, 2.2, 3)
t2 = (1, 2.2, 3)
# print(cmp(t1, t2))

# dir(): 사용 가능한 함수를 출력해줌.
print(dir(t1))
print('---------------------------------')

# 튜플을 비교하려면 __eq__() 쓰기.
print(t1.__eq__(t2))
