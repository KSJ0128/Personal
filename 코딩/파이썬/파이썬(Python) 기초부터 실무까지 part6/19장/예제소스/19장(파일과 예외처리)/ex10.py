# 디렉토리에 관련된 실습
import os
# 현재 작업 디렉토리를 얻는 방법
dir = os.getcwd()
print(dir)

print("----------------")
# 작업 디렉토리 안에 파일들의 리스트를 얻고자 할때..디렉토리 반환
for filename in os.listdir():
    print(filename)

print("----------------")
# 파일만 추출하고자 할때..
for filename in os.listdir():
    if os.path.isfile(filename):
        print(filename, "파일입니다.")

print("----------------")
# 파일의 확장자가 .png 만 걸러내고자 할때 endswith()를 사용한다.
files = os.listdir()
for name in files:
    if os.path.isfile(name):
        if name.endswith(".png"):
            print(name)