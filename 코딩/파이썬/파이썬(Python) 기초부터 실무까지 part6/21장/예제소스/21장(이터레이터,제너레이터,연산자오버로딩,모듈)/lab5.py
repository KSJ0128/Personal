# 문제2
# 클래스 2개를 만드는데 먼저 Figure 클래스를 만들고 생성자에서 width 와 height 를 받아서
# 초기화 한다.그 다음 Quadrangle 클래스를 만들어 아래와 같이 출력결과가 나오도록 프로그램
# 을 작성하시오.
# 출력결과
# 너비의 합 : 5
# 높이의 합 : 7
# ---------------------------------------------------------------------------
# 풀이
class Figure(object):
    def __init__(self, width, height):
        self.width = width
        self.height = height

class Quadrangle(object):
    def __init__(self, width, height):
        self.width = width
        self.height = height
    # 연산자 + 중복 정의
    def __add__(self, other):
        return Quadrangle(self.width + other.width, self.height + other.height)

quad = Quadrangle(1,2)
figure = Figure(4,5)
print("너비의 합 : ", quad.width + figure.width)
print("높이의 합 : ", quad.height + figure.height)








