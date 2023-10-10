# 기본적인 파일 입출력 실습
data = []

# 파일 경로를 지정하고 읽기 모드로 문자셋 utf-8로 설정해 파일을 연다. 그리고 그 주소를 반환.
# r모드는 읽기 모드.
fp = open('/Users/seojin/a.txt', mode = 'r', encoding = 'UTF-8')
#print(type(fp))

# readlines(): 파일의 모든 줄을 읽어온다.
for line in fp.readlines():
    # .strip()을 통해 문자열의 공백(줄바꿈 문자)을 제거한 후 출력.
    # print(line.strip())
    data.append(line.strip())

# 프로그램을 다 사용했으면 반드시 close()를 통해 파일을 종료.
print('파일에서 읽은 내용입니다.')
print(data)
fp.close()

# 파일 내용 작성. w모드는 덮어쓰기 한다고 생각.
fp = open('/Users/seojin/a.txt', mode = 'w', encoding = 'UTF-8')
fp.write('우리는 파이썬을 공부합니다.')
fp.write('저희도 파이썬을 공부합니다.')
print('쓰기 완료')
fp. close()

# a모드는 기존 파일 내용에 추가.
fp = open('/Users/seojin/a.txt', mode = 'a', encoding = 'UTF-8')
fp.write('11. 우리는 파이썬을 공부합니다.')
fp.write('22. 저희도 파이썬을 공부합니다.')
print('추가 완료')
fp. close()

# csv 파일 읽는 법
import csv

fp = open('/Users/seojin/test.csv', mode = 'r', encoding = 'UTF-8')
# reader 메서드로 csv 파일 읽음.
reader = csv.reader(fp)

for txt in reader:
    print(txt)