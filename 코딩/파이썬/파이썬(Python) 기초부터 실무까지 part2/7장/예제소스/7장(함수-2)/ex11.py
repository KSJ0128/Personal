# 여러 개의 값을 반환하는 함수 실습
# 타 프로그래밍 언어에서는 함수가 항상 하나의 값만을 반환하거나 반환값이
# 없다.파이썬에서는 튜플을 이용하여 여러 개의 값을 반환할 수가 있다.
# 튜플(tuple)은 몇 가지만 제외하고 리스트와 거의 비슷한 자료구조 형태이다.
# - 리스트는 []으로 값을 둘러싸지만, 튜플의 ()로 값을 둘러싸는 형태이다.
# - 리스트는 변경가능한 객체(생성, 삭제, 수정, 추가)이지만, 튜플은 한 번
#   값으로 만들면 그 값을 변경할 수 없는 객체이다.

# 파이썬에서는 튜플의 형태로 여러 개의 값을 리턴을 하긴 하지만,
# 함수는 한 가지의 값을 리턴해준다라는 그 정설에는 부합하다.
# 그 이유는 튜플이라는 형태로 1개를 넘기기 때문이다.
def tuple_return():
    return 1, "안녕", 5

a, b, c = tuple_return()
tuple_variable = tuple_return()
# 값을 추가 할수가 없다. 변경 불가능한 객체이기 때문이다.
# tuple_variable += 10

li = list(tuple_variable)
li.append("반갑습니다.")
print(li)
print(a, b, c)
print(tuple_variable)
print(type(tuple_variable))