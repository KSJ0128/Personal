# 조상클래스 Shape 정의
import turtle
import random
class Shape:
    myTurtle = None
    cx, cy = 0, 0    # 도형의 중심점

    # 기본생성자
    def __init__(self):
        # Turtle 인스턴스 생성
        self.myTurtle = turtle.Turtle()
    # 펜 색상과 두께 무작위로 뽑기
    def setPen(self):
        r = random.random()   # 0.0 <= 값 < 1.0
        g = random.random()  # 0.0 <= 값 < 1.0
        b = random.random()  # 0.0 <= 값 < 1.0
        print("r:",r,"g:",g,"b:",b)
        self.myTurtle.pencolor((r,g,b))   # 펜 색상 지정하기
        penSize = random.randrange(1,20)  # 펜의 굵기를 임의로 얻는다
        self.myTurtle.pensize(penSize)    # 펜의 굵기를 지정
    # Shape 클래스를 상속받는 클래스들은 필요에 의해서 drawShape() 를 오버라이딩
    # 할 수 있도록 선언부 선언과 아무런 내용이 없는 구현부를 만들어 두었다.
    def drawShape(self):
        pass