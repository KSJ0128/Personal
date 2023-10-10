# 자손클래스 DropShip 클래스 정의
from Unit import *

class DropShip(Unit):
    mode = ""
    # 조상클래스의 추상메서드 오버라이딩
    def move(self, x, y):
        self.x = x
        self.y = y
        print("드랍쉽의 위치 : ", self.x, ",", self.y, "로 이동함")
    # 드랍쉽의 자신만의 고유 기능을 추가
    def load(self):
        self.mode = "탑승모드 : 유닛 탑승 완료!"
        print(self.mode)

    def unload(self):
        self.mode = "탑승모드 : 유닛 하강 완료!"
        print(self.mode)