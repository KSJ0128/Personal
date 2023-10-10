# 제너레이터에 대한 실습
# 제너레이터(generators)는 키워드 yield 를 사용해서 함수로부터 반복 가능한 객체를
# 생성하는 방법이다.yield 키워드로 함수를 제너레이터를 만들 수 있다.
# 이터레이터(iterators)는 클래스를 반복가능한 클래스로 만들어 주는 것이며, 또한 모든
# 로직을 수행한 후 한번에 메모리에 적재를 해서 출력한다.그에 반해 제너레이터는 yield
# 키워드로 되어있는 문장을 실행하면 대기상태로 빠지고 다음 문장을 실행한다.그리고 난후
# 다시 yield 키워드를 만나면 또 다시 또 대기상태 빠지는 그러한 형태를 취하며 아울러
# 메모리 적재방식에서도 하나하나씩 출력을 한다는 것이 차이점이다.

# def MyCounterGen(low, high):
#     while low <= high:
#         yield low
#         low += 1
#
# if __name__ == "__main__":
#     for n in MyCounterGen(1, 10):
#         print(n, end=" ")

import time
def gen(count):
    start = 1
    while start <= count:
        yield start     # yield 를 실행하고 대기 상태로 빠진다.
        time.sleep(2)   # yield start 를 실행한 후 2초간 대기
        print("while 문 start 값 : ", start)
        start += 1


if __name__ == "__main__":
    for n in gen(3):
        print("for 문 실행 n값 : ", n, end=" ")