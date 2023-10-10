# 조상클래스 정의
class Disk(object):
    __capacity = 0   # 용량
    __rpm = 0        # 속도

    def __init__(self, capacity, rpm):
        self.__capacity = capacity
        self.__rpm = rpm

    def getCapcity(self):
        return self.__capacity

    def getRpm(self):
        return self.__rpm

    def showPrint(self):
        return "디스크의 용량은 " + str(self.__capacity) + "GB 이며" \
               "RPM 은 " + str(self.__rpm) + "입니다."



