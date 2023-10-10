# 정렬과 탐색의 실습
# sort()메소드와 sorted()내장함수의 차이점

# sorted()내장함수는 원본 리스트를 변경을 시키지 아니하고 정렬된 리스트를 반환한다.
# sorted()내장함수는 반복가능한 객체들을 다 매개변수로 받을 수 있는 장점이 있다.
a = [4,2,1,5,7,-1]
b = sorted(a)

print(a)
print(b)
print(id(a))
print(id(b))
print("-------------------------------")
# 리스트만의 메소드인 sort()는 원본 리스트에 영향을 주며 리턴값은 None 이다.
x = [1,4,2,-10,-99]
y = x.sort()
print(x)
print(y)
print("-------------------------------")
# sorted()를 이용하여 매개변수를 딕셔너리를 주면 키값으로 오름차순 정렬이 이루어진다.
print(sorted({3:"D", 2:"B", 5:"B", 4:"E", 1:"A"}))
print("-------------------------------")

# key 매개변수 실습
# key=str.lower 은 대소문자 구별 없이....
print(sorted("가는 고향 아쉬운 사람 The Health not of their but".split(), key=str.lower))
# 튜플 리스트를 만들어서 key 매개변수에 정렬하는 기준을 제시
students = [
    ("신은혁", 4.4, 20210703),
    ("김연아", 4.5, 20210702),
    ("손연재", 4.3, 20210701)
]
# students 튜플리스트의 학번을 기준으로 오름차순 정렬이 이루어진다.
print(sorted(students, key=lambda students: students[2]))
print("-------------------------------")

# 오름차순 정렬과 내림차순 정렬
# sort(), sorted()함수에는 reverse 매개변수가 존재한다. reverse 매개변수를 이용하여
# 내림차순, 오름차순을 결정지을 수가 있다.
print(sorted(students, key=lambda students: students[0], reverse=True))
print("---------------------------------------")
# 정렬의 안정성
# 안정성이란 동일한 키값을 가지고 있는 행(레코드)이 여러 개 존재하더라도 행의 순서가 그대로 유지가
# 되는 성질을 안정성이라고 한다.
data = [(1,200),(1,100),(1,300),(2,100),(2,200)]
print(sorted(data, key=lambda data:data[0]))


