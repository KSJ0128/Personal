# 문제1
# random 모듈에 있는 함수를 사용해서 7개의 단어 중에서 랜덤하게 3개를 선택하여
# 출력하는 프로그램을 작성하여 보자
import random
words = []
words.append("파이썬")
words.append("C언어")
words.append("학습")
words.append("프로그램")
words.append("코딩")
words.append("마우스")
words.append("컴퓨터")
print(words)
# -------------------------------------------------------------------
# 풀이
result = ""
for i in range(0,3):
    result += random.choice(words) + " "

print("추출한 word 3개 : ", result)
print("----------------------------------")

# 문제2
# random 모듈에 있는 함수를 사용하여서 알파벳 a부터 z사이에서 랜덤하게 10개의 문자를
# 출력하는 프로그램을 작성하시오.
str1 = "abcdefghijklmnopqrstuvwxyz"
# ----------------------------------------------------------
# 풀이
for i in range(0, 10):
    letter = random.choice(str1)
    print("알파벳에서 추출한 10개의 문자",i+1," : ",letter)
print("-----------------------------------------------")
# 과제
# 중복된 알파벳은 제외하고 출력해보기

# 문제3
# 100과 200사이에서 5개의 짝수 난수를 발생시키는 프로그램을 작성하시오(random.sample())
# ------------------------------------------------------------
# 풀이
print("100~200사이 짝수 난수 5개 : ",
      random.sample([i for i in range(100,201) if i%2 == 0], 5))