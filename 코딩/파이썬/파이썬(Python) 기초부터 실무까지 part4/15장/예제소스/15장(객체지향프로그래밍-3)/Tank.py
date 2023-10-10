from Unit import *

class Tank(Unit):
    mode = ""
    # 조상클래스의 추상메서드 오버라이딩
    def move(self, x, y):
        self.x = x
        self.y = y
        print("탱크의 위치 : ", self.x, ",", self.y, "로 이동함")
    # 탱크의 자신만의 고유 기능을 추가
    def sizeMode(self):
        self.mode = "공격모드 : 시즈모드 변환"
        print(self.mode)
