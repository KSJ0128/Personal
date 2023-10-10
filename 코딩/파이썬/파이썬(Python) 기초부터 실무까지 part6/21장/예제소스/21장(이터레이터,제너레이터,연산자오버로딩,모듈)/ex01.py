# 이터레이터에 대한 실습
# 이터레이터라는 것은 객체를 반복가능한 객체로 만들어 주는 것
# __iter__(), __next__() 2개의 메소드를 클래스에 정의를 해주어야 비로소
# 반복가능하게 되는 것이다.
class MyCounter(object):
    # 생성자를 정의(초기화 메서드)
    def __init__(self, low, high):
        self.current = low
        self.high = high
    # 반복가능한 객체가 되기 위해서 아래 2가지 메소드를 추가 및 정의를 한다.
    # __iter__() 메소드는 자기 자신을 반환하게끔 정의를 하도록 한다.
    def __iter__(self):
        return self

    def __next__(self):
        # current 값이 high 값을 초과하게 되면 StopIteration 예외를 발생하게 하였다.
        if self.current > self.high:
            raise StopIteration
        else:
            self.current += 1
            # self.current 값이 1을 증가했지만 이전값을 출력을 하기 위해서 -1 해서 리턴해준다.
            return self.current - 1

if __name__ == "__main__":
    counter = MyCounter(1, 10)    # 생성자 호출
    for n in counter:
        print(n, end=" ")