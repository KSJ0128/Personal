# 파일은 데이터를 영구적으로 저장하는 형태이다.
# 파일을 다루는 방법에 대해서 알아보자.
# 1.파일을 열기
# open()내장 함수는 파일을 열고자 할 때 사용하는 함수이다.
file = open("c:\\Temp\\test.txt", "r", encoding="UTF-8")
# readline() 함수는 파일에서 내용을 읽어오는데 줄단위 읽어온다.
# 개행문자(\n)까지 가져온다.
line = file.readline().rstrip()
# while line != "":
#     print(line)
#     line = file.readline()
while line != "":
    print(line)
    # rstrip() 는 오른쪽에 공백을 제거하는 함수인데 \n, \t 등을 다 제거를 해준다.
    line = file.readline().rstrip()
file.close()