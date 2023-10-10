# 무명함수(익명함수, anonymous function)에 대한 실습
# 무명함수는 함수명이 없고, 구현부만 존재한다. 파이썬에서는 무명함수를 만들때
# lambda 키워드로 만들 수 있다.
# 무명함수는 print()등과 같은 일반함수를 호출할 수가 없다.오직 계산만 가능하다.
# 전역변수를 참조할 수가 없다.
# lambda 인수1, 인수2 : 수식  <-- 문법


def main():
    print("두 정의 합 : ", get_sum(10, 50))
    print("두 정의 합 : ", get_sum(100, 50))

    # lambda 키워드를 이용한 sum() 만들기
    # 람다 함수는 코드 안에 함수를 포함하는 어느 곳이든지 다 사용이 가능하다.
    # 가장 많이 사용되는 곳은 GUI 프로그램에서 이벤트를 처리하는 콜백 함수 형태로
    # 많이 사용된다
    sum = lambda x, y: x + y
    print("람다식을 이용한 함수명 sum() 결과 : ", sum(10, 50))
    print("람다식을 이용한 함수명 sum() 결과 : ", sum(10, 150))
    # 람다식으로 구성되어진 리스트 데이터
    li = [lambda x: x ** 2, lambda x: x ** 3, lambda x: x ** 4]
    for f in li:
        print(f(10))
    # 람다함수를 출력을 하면 결과론으로 함수 객체를 출력하는 형태가 된다.
    print(lambda x, y: x + y)
    # 아래 코드가 실질적으로 람다식을 이용한 무명함수를 직접 호출한 형태
    print((lambda x, y: x + y)(10, 50))

# 일반적인 함수
def get_sum(x, y):
    return x + y

# 람다함수에서는 변수에다 값을 할당할 수 없다.
# lambda x=10, y : x + y
main()