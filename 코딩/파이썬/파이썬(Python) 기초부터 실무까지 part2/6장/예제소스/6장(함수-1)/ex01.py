# 함수(function)에 대한 실습
# 1. 함수는 프로그램 안에서 중복된 코드를 제거한다.
# 2. 복잡한 프로그래밍 작업을 더 간단한 작업들로 분해할 수 있다.
# 3. 함수는 한번 만들어두면 재사용이 얼마든지 가능하다.
# 4. 함수를 사용하면 가독성이 증대되고, 유지관리도 쉬워진다.

# hello 파일의 내용을 전부 다 가져오기 때문에 파일이름.함수명으로 접근할 필요가 없고
# 함수명만 호출하면 된다.
from hello import *
# 파일명.함수명으로 접근해야 한다.
# import hello

# 함수 호출(function call)
say_hello_name("신은혁")
say_hello_name("홍길동")
# 함수가 호출되어 10을 출력을 하긴 하지만 가독성이 좋지않다.
# 이유는 함수의 매개변수명이 name 이니 웬만하면 이름을 매개변수 값으로 주는
# 것이 현명한 코드가 될 것이다.
# say_hello(10)

# 파이썬에서는 오버로딩의 개념이 없다. 같은 함수의 이름이라면 마지막에 정의되어진
# 함수만 인식하게 된다.하여, 함수명은 유니크한 값으로 함수명을 짓도록 한다.
say_hello_name_msg("신은혁"," 반갑습니다.")
say_hello_name_msg("홍길동"," 도와주세요.")

# get_sum()를 이용하여 범위값의 누적합을 구하는 코드
result = get_sum(1, 10)
print(type(result))
print("1~10 누적합 : ", result)

result = get_sum(1, 30)
print(type(result))
print("1~10 누적합 : ", result)

result = get_sum(1, 100)
print(type(result))
print("1~10 누적합 : ", result)