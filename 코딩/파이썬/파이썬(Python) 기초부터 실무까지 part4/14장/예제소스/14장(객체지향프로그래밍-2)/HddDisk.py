from Disk import *
# 자손클래스 정의
class HddDisk(Disk):
    __capacity = 0
    __rpm = 0

    def __init__(self, capacity, rpm):
        Disk.__init__(self, 10, 50)
        self.__capacity = capacity
        self.__rpm = rpm

    def getCapcity(self):
        return self.__capacity

    def getRpm(self):
        return self.__rpm

    def showPrint(self):
        # return "Hdd 디스크의 용량은 " + str(super().getCapcity()) + "GB 이며" \
        #        " RPM 은 " + str(super().getRpm()) + "입니다."
        return "Hdd 디스크의 용량은 " + str(self.getCapcity()) + "GB 이며" \
               " RPM 은 " + str(self.getRpm()) + "입니다."