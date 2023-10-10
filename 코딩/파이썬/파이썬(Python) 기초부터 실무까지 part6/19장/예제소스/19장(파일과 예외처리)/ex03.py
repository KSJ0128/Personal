# 파일을 닫는 3가지 방법

# 1번째 방법 : close() 호출
# 단점은 파일을 가지고 작업하다가 에러가 발생하면 파일이 제대로 닫히지 않는 경우가
# 발생한다.
file = open("c:/Temp/test.txt", "r",encoding="UTF-8")
line = file.readline().rstrip()
print(line)
# print(exce)
file.close()

# 2번째 방법 : try...finally
try:
    file = open("c:/Temp/test.txt", "r", encoding="UTF-8")
    line = file.readline().rstrip()
    print(line)
    # print(exce)
finally:                  # 무조건 실행되는 부분이기 때문에 1번째 방법보다 안전하다.
    print("finally")
    file.close()

# 3번째 방법 : with 명령문, with 명령문 내의 블록이 종료될 때 파일이 자동으로 닫힌다.
# close() 내부적으로 호출이 된다.(권장 방법)
with open("c:/Temp/test.txt", "r", encoding="UTF-8") as file:
    line = file.readline().rstrip()
    print(line)
    # print(exce)
