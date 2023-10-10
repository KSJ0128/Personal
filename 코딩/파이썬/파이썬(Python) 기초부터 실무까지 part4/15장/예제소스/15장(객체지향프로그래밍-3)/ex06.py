# 추상클래스의 실습
# 추상클래스 : 클래스안에 최소 추상메서드가 1개 이상 존재하면 그 클래
# 스를 추상클래스다라고 함.
# abc(abstract base class 약자)모듈을 이용하여 만든다.
# @abstractmethod 라는 어노테이션을 추상메서드 위에 붙여준다.
# 추상메서드는 선언부만 존재하고 구현부는 없는 메서드이다.
# 추상클래스는 인스턴스를 절대로 생성할 수가 없다.
from abc import *

class StudentBase(metaclass=ABCMeta):
    # 아래 어노테이션은 인터프리터에게 study 메서드가 추상메서이다
    # 이니 잘 체크해라 라는 명령을 준다.
    @abstractmethod
    def study(self):
        pass

    @abstractmethod
    def go_to_school(self):
        pass

# Student 클래스는 인스턴스를 만들 수 없다. 그 이유는 추상메서드 1개
# 를 재정의 하지 않았기 때문이다.
class Student(StudentBase):
    def study(self):
        print("공부를 합니다.")

class Student1(Student):
    def go_to_school(self):
        print("학교를 갑니다.")

if __name__ == "__main__":
    # 추상클래스는 절대로 인스턴스를 생성할 수가 없다.
    # 상속을 통하여 자손클래스에서 추상메서드를 전부 오버라이딩을
    # 했을때 인스턴스 생성이 가능하다.(중요)
    # student = StudentBase()
    # student = Student()
    student1 = Student1()
    student1.study()
    student1.go_to_school()


# 추상클래스의 용도 : 추상클래스를 상속받는 각각의 자손클래스에서
# 다른 내용으로 구현될 것을 예상하고 뼈대(가이드 라인)만 만든다
# 라는 것이다.
# 예) 추상클래스에 play() 추상메서드가 존재한다면 mp3, cdplayer,
# lpplayer, tapeplayer 클래에는 play() 메서드 다 존재할 것이다.
# play() 메서드는 선언부만 같은 다른 내용으로 오버라이딩이 되어
# 다른 결과를 만들어줄 수가 있다.