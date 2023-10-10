# Unit, Tank, DropShip, Marine 클래스의 실행파일
from Tank import *
from DropShip import *
from Marine import *

if __name__ == "__main__":
    print("-------------------------")
    tank = Tank()
    tank.move(100, 300)
    tank.sizeMode()
    tank.stop("탱크", 300, 400)
    print("-------------------------")
    marine = Marine()
    marine.move(200, 550)
    marine.stimPack()
    marine.stop("마린", 300, 400)
    print("-------------------------")
    dropShip = DropShip()
    dropShip.move(1000, 2000)
    dropShip.load()
    dropShip.unload()
    dropShip.stop("드랍쉽", 0, 0)
    print("-------------------------")