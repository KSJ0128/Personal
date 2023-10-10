# 특수 메소드 실습

# Vector2D 클래스 정의
class Vector2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # 특수 메소드 __add__()정의(2개의 인스턴스를 매개변수를 받는다)
    def __add__(self, other):
        # 인스턴스의 더하기 연산을 하고 그 해당하는 값을 가지고 새로운
        # 인스턴스를 생성하여 리턴해준다.
        add_instance = Vector2D(self.x + other.x, self.y + other.y)
        # return Vector2D(self.x + other.x, self.y + other.y)
        return add_instance

    # 특수 메소드 __sub__()정의(2개의 인스턴스를 매개변수를 받는다)
    def __sub__(self, other):
        return Vector2D(self.x - other.x, self.y - other.y)

    # 특수 메소드 __mul__()정의(2개의 인스턴스를 매개변수를 받는다)
    def __mul__(self, other):
        return Vector2D(self.x * other.x, self.y * other.y)

    # 특수 메소드 __eq__()정의(2개의 인스턴스를 매개변수를 받는다)
    def __eq__(self, other):
        return (self.x == other.x) and (self.y == other.y)
    # 인스턴스의 멤버변수들의 값을 출력해주는 메서드이며
    # print(인스턴스명) 자동으로 호출이 되는 메서드이다.
    def __str__(self):
        return "(%g, %g)" % (self.x, self.y)

if __name__ == "__main__":
    v1 = Vector2D(5, 2)
    v2 = Vector2D(5, 3)
    v3 = Vector2D(5, 4)
    vector_result = v1 + v2
    print(vector_result.__str__())

    vector_result = v1 - v2
    print(vector_result.__str__())

    vector_result = v1 * v3
    print(vector_result.__str__())

    if v1 == v3:
        print("v1과 v3는 논리적 동등한 인스턴스입니다.")
    else:
        print("v1과 v3는 논리적 동등하지 않은 인스턴스입니다.")