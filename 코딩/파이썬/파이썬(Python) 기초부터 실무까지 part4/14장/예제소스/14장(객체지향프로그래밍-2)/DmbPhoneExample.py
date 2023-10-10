# Phone 클래스와 DmbPhone 클래스를 이용하여 메인코드 작성부분
from DmbPhone import *
if __name__ == "__main__":
    # 자손클래스의 인스턴스 생성
    dmbPhone = DmbPhone("파이썬폰", "검정", 10)

    # 조상클래스에게 상속받은 필드
    print("모델 : ", dmbPhone.model)
    print("색상 : ", dmbPhone.color)
    # 자손클래스 필드
    print("채널 : ", dmbPhone.channel)

    dmbPhone.powerOn()
    dmbPhone.bell()
    dmbPhone.sendVoice("여보세요")
    dmbPhone.receiveVoice("안녕하세요! 저는 홍길동입니다.")
    dmbPhone.sendVoice("아 안녕하세요 반갑습니다.")
    dmbPhone.hangUp()
    print("------------------------------")
    # 자손클래스에서 만든 DMB 기능
    dmbPhone.turnOnDmb()
    dmbPhone.changeChannelDmb(15)
    dmbPhone.turnOffDmb()
