# 클래스의 상속 : 조상(부모, 슈퍼)클래스의 멤버(필드, 메서드, 생성자
# 제외)들을 그대로 자손(자식, 서브)클래스가 물려받아 새로운 클래스를
# 만드는 것이다. 이렇게 상속이 이루어지면 직접적인 관계가 이루어진다.
# 조상클래스의 멤버가 추가, 삭제, 수정에 따라서 자손클래스가 영향을 받
# 는다.역으로 자손클래스의 멤버가 추가, 삭제, 수정가 되면 조상클래스에
# 영향을 끼치지 아니한다.
# 자손클래스로 내려가면 갈수록 멤버의 갯수가 많아지고 반대로 조상클래스로
# 올라가면 멤버의 갯수가 적어진다.

# 조상클래스
class Car():
    # 조상클래스의 멤버는 3개이다.
    def __init__(self):
        self.speed = 0
        self.door = 0

    def upSpped(self, speed):
        self.speed += speed
        print("현재속도(조상클래스) : %d" % self.speed)
        print("문의 갯수(조상클래스) : %d" % self.door)

# 자손클래스
class Sedan(Car):
    # 자손클래스의 멤버는 4개가 되는 것이다.
    def __init__(self, speed, door):
        # 조상클래스의 생성자를 호출하는 부분이다.
        # 조상없는 자손이 있는가?
        Car.__init__(self)
        self.speed = speed
        self.door = door
    # 자손클래스에서 추가한 메서드
    def downSpped(self, speed):
        self.speed -= speed
        print("현재속도(자손클래스) : %d" % self.speed)

if __name__ == "__main__":
    # car 인스턴스에는 downSpeed() 메서드가 없다.하여 호출할 수가 없다.
    car = Car()
    car.upSpped(50)       # Car 클래스의 메서드 호출
    print("car 주소 : ", id(car))
    sedan = Sedan(100, 4)
    print("sedan 주소 : ", id(sedan))
    sedan.upSpped(150)    # 조상클래스 메서드 호출
    sedan.downSpped(100)  # 자손클래스 메서드 호출

