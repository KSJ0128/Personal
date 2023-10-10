# 지역변수와 전역변수의 실습

# def test():
#     # 함수 안에서 하나의 변수가 전역변수가 되었다가 다시 지역변수가 될 수가
#     # 없는 것이다.
#     # print(text)
#     text = "파이썬 공부"
#     print(text)
#
# text = "자바 공부"
# test()
# print(text)

# 전역변수를 함수 안에서 값을 변경하고자 한다면....global 키워드를 명시적으로 함수 안에
# 적어줘야 한다.
def test():
    # test() 함수 안에서 전역변수인 text 를 사용하겠다라는 것을 인터프리터한테 알린다.
    global text
    print(text)
    text = "파이썬 공부"     # 전역변수의 값을 변경하고 있다.
    print(text)

text = "자바 공부"
print(text)     # 전역변수의 값이 변경되기 전에 출력
test()
print(text)     # 전역변수의 값이 변경 후에 출력