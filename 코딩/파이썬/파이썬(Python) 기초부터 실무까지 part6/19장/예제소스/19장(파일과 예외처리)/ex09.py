# 최저 기온을 구하기
import csv

f = open("files/weather.csv", "r")
data = csv.reader(f)
header = next(data)     # 헤더 제거하기
temp = 1000

for row in data:
    if temp > float(row[3]):    # 최저기온은 3번 인덱스에 위치하고 있다.
        temp = float(row[3])

print("가장 추웠던 온도는 ", temp,"입니다.")
f.close()
