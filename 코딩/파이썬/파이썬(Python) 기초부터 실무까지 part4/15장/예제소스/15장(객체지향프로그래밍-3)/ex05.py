# 다형성 실습
class Product:
    price = 0
    bonusPoint = 0
    # 매개변수를 있는 생성자
    def __init__(self, price):
        self.price = price
        # 보너스 점수는 제품 가격의 10프로를 적립함.
        self.bonusPoint = int(self.price / 10.0)

class Tv(Product):
    def __init__(self, price):
        # 조상클래스의 생성자 호출
        super().__init__(price)
    # 무엇을 구매를 했는지 확인하기 위해서 __str__ 재정의
    def __str__(self):
        return "TV"

class Computer(Product):
    def __init__(self, price):
        # 조상클래스의 생성자 호출
        super().__init__(price)
    # 무엇을 구매를 했는지 확인하기 위해서 __str__ 재정의
    def __str__(self):
        return "COMPUTER"

class Audio(Product):
    def __init__(self, price):
        # 조상클래스의 생성자 호출
        super().__init__(price)
    # 무엇을 구매를 했는지 확인하기 위해서 __str__ 재정의
    def __str__(self):
        return "AUDIO"

# 물건을 사는 독립적 클래스
class Buyer:
    money = 1000
    bonusPoint = 0
    # 매개변수의 다형성을 이용
    def buy(self, product):
        # 가진 돈보다 제품의 가격이 비싼 경우
        if self.money < product.price:
            print("잔액이 부족하여 물건 구입이 안됩니다.")
            return
        # 가진 돈에서 구입한 제품의 가격을 빼준다.
        self.money -= product.price
        # 제품의 보너스 점수를 추가한다.
        self.bonusPoint += product.bonusPoint
        print(product.__str__() + "를 구매하셨습니다.")

if __name__ == "__main__":
    buyer = Buyer()
    tv = Tv(300)
    computer = Computer(100)
    audio = Audio(50)
    # 생성된 인스턴스를 Buyer 클래스의 buy()메서드의 매개변수 값으로 대입하고
    # 있다.
    buyer.buy(tv)
    buyer.buy(computer)
    buyer.buy(audio)

    buyer.buy(Tv(300))
    buyer.buy(Computer(100))
    buyer.buy(Tv(500))

    print("현재 잔액 : " , buyer.money,"만원")
    print("현재 보너스 포인트 : ", buyer.bonusPoint,"점")
