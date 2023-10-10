# Disk, HddDisk 의 실행파일
from HddDisk import *

if __name__ == "__main__":
    disk = Disk(500, 7200)
    hddDisk = HddDisk(32, 520)

    print(disk.showPrint())
    print(hddDisk.showPrint())
