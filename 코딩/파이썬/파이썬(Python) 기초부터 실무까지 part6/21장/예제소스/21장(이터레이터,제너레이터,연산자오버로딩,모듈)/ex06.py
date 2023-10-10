# 연산자 오버로딩 실습-2
class NumBox(object):
    def __init__(self, num):
        self.num = num
    def __add__(self, num):
        self.num += num
    def __sub__(self, num):
        self.num -= num
    def __radd__(self, num):
        self.num += num
    def __rsub__(self, num):
        self.num -= num

n = NumBox(40)
# 객체와 int 간에는 연산이 안이루어진다.
# 하여 클래스 안에 __add__()특수 메소드를 재정의 하면 비로소 연산이
# 이루어지고 출력이 되는 것을 볼 수가 있다.
# 아래 2줄의 코드는 같은 역할을 한다.
n + 100
n.__add__(100)
print(n.num)
# print(n.num)
n - 110
n.__sub__(110)
print(n.num)

# __add__()를 재정의를 한다고 해도 아래와 같이 자리를 바꿔버리면 에러가
# 발생함을 알수가 있다.이 때는 + 연산자는 __add__()를 호출하지 않고 __r
# add__()메소드를 호출한다.
110 + n
print(n.num)

110 - n
print(n.num)



