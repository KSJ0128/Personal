# 정수를 받고자 할때의 예외처리

# try:
#     n = int(input("숫자를 입력하세요 : "))
# except ValueError:
#     print("정수가 아닙니다.")


# 파일의 대한 예외처리
# infile = None
# try:
#     fname = input("파일 이름을 입력하세요 : ")
#     infile = open(fname, "r")
# except FileNotFoundError:
#     print("해당하는 파일이 존재하지 않습니다.")

# infile = None
# try:
#     infile = open("files/test.txt", "w")
#     infile.write("파일에 내용을 기재합니다.")
# except FileNotFoundError:
#     print("해당하는 파일이 존재하지 않습니다.")
# finally:
#     infile.close()

# 강제로 예외를 발생시키는 구문
raise NameError("비밀번호가 잘못되었습니다.")


