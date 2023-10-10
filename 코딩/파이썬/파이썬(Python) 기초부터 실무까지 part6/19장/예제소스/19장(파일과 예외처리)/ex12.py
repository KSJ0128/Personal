# 정규식 실습
import re

# file = open("files/uscons.txt", "r")
# for line in file:
#     line = line.rstrip()    # 오른쪽 공백 없애기
#     if re.search('^[0-9]+', line):     # 숫자로 시작하는 문장 걸러내는 조건식
#         print(line)

# 문자열 생성
text = """101 COM Python Program
102 MAT     LinearAlgebra
103 ENG     Computer"""
# findall()는 파일이나 문자열에서 찾고자 하는 것을 모두 찾는다.
s = re.findall('\d+', text)    # 숫자 1번 이상 반복하는 정규표현식
print(s)



