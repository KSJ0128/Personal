# 클래스의 다중상속에 대한 실습
# 다중상속 : 여러 조상클래스로부터 상속을 받아서 새로운 클래스를 만드는 것
# 조상클래스를 몇 개를 상속을 받아도 상관 없다.
# 다중상속 문제점
# 1. 다중상속을 하다 보면 조상클래스에서 같이 이름을 가진 멤버가 존재할 수
# 있기 때문에 충돌성을 배제할 수가 없다.
# 2. 하나의 조상클래스를 두 번 이상 상속을 받을 가능성이 농후하다.
# 파이썬에서는 단일, 다중상속을 다 지원하기 때문에 알고는 넘어가도록 하자.
class Person(object):
    def __init__(self):
        pass
    def greeting(self):
        print("안녕하세요.")

class University(object):
    def __init__(self):
        pass
    def manage_credit(self):
        print("학점관리를 합니다.")

# 2개의 조상클래스를 상속 받음
class Undergraduate(Person, University):
    def __init__(self):
        # 조상클래스를 2개를 상속받았기에 생성자도 각 조상클래스에
        # 해당하는 부분을 호출을 다 해줘야 한다.
        Person.__init__(self)
        University.__init__(self)
    # 멤버가 3개
    def study(self):
        print("공부를 합니다.")

if __name__ == "__main__":
    student = Undergraduate()
    student.greeting()
    student.manage_credit()
    student.study()