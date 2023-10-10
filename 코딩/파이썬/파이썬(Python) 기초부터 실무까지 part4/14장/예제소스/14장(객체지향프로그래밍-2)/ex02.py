# 특수 메소드 : 인스턴스 간에 산술연산과 비교연산을 해주는 메소드
# 예) 인스턴스 a, b가 존재한다면 a + b 를 하게되면 주소 + 주소가
# 되는 형태이기 때문에 연산자체가 불가하다.
# + 연산이 가능하게끔 하기 위해서 __add()__클래스 안에 메소드로
# 정의를 해주면 피연산자가 인스턴스라면 + 연산을 하게되면 자동으로
# __add()__호출해준다.

# == 연산 실습
class Circle:
    def __init__(self, radius=0):
        self.radius = radius
    # 2개의 인스턴스를 매개변수로 받는다.(주소값 공유)
    def __eq__(self, other):
        print("__eq__()호출됨")
        return self.radius == other.radius

if __name__ == "__main__":
    circle1 = Circle(10)
    circle2 = Circle(10)
    # 주소값끼리의 연산은 불가능하다.인스턴스간의 == 연산자는 __eq()__
    # 메소드를 호출하는 것이다.
    if circle1 == circle2:  
        print("원의 반지름이 동일합니다.")

