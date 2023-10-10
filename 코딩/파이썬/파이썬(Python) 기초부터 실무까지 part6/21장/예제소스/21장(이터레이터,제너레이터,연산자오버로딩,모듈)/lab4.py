# 문제1
# 원(Circle)을 나타내는 클래스를 만들고 radius(반지름)을 생성자의 매개변수
# 로 받아서 초기화 하고 getter(),setter(),area() 즉, 원의 면적을 구하는
# 메소드 작성하고, Circle 클래스에 +, >, < 연산자를 중복 정의 해보시오
# 출력결과는 아래와 같이 나오게 하시오
# 출력결과
# c1의 반지름 :  4
# c2의 반지름 :  5
# c1의 반지름과 c2의 반지름을 합한 값 :  9
# c3 > c2의 결과 :  True
# c1 < c2의 결과 :  True
# 원의 반지름: 9
# -------------------------------------------------------------------
import math
class Circle(object):
    # 생성자
    def __init__(self, radius):
        self.radius = radius
    # getter()메소드
    def getRadius(self):
        return self.radius
    # setter()메소드
    def setRadius(self, radius):
        self.radius = radius
    # 면적을 구하는 메소드
    def area(self):
        return math.pi * self.radius ** 2
    # 산술 연산자 중복정의(+)
    def __add__(self, other):
        return Circle(self.radius + other.radius)
    # 비교 연산자 중복정의(>)
    def __gt__(self, other):
        return self.radius > other.radius
    # 비교 연산자 중복정의(<)
    def __lt__(self, other):
        return self.radius < other.radius
    # 문자열 출력
    def __str__(self):
        return "원의 반지름 : " + str(self.radius)

c1 = Circle(4)
print("c1의 반지름 : ", c1.getRadius())
c2 = Circle(5)
print("c2의 반지름 : ", c2.getRadius())
c3 = c1 + c2
print("c1의 반지름과 c2의 반지름을 합한 값 : ", c3.getRadius())
print("c3 > c2의 결과 : ", c3 > c2)
print("c1 < c2의 결과 : ", c1 < c2)
print(c3)