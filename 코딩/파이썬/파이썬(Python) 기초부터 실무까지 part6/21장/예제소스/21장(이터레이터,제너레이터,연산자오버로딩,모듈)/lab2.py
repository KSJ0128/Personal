# 문제2
# 이터레이터를 구현하는 MyEnumerate 라는 클래스를 작성해보자.튜플의
# 첫 번째 요소 0으로 시작되는 인덱이고 튜플의 두 번째 요소는 주어진
# 자료구조의 현재 요소이다.각 반복마다 튜플을 반환해야 한다.
# for index, letter in MyEnumerate("abc"):
#     print(index. ":", letter)
# 실행결과
# 0 : a
# 1 : b
# 2 : c
# ----------------------------------------------------------
# 풀이
class MyEnumerate(object):
    def __init__(self, data):
        self.data = data
        self.index = 0
    # 2개의 추가 메서드를 정의한다.
    def __iter__(self):
        return self
    def __next__(self):
        if self.index >= len(self.data):
            raise StopIteration
        # 인덱스와 인덱스에 해당하는 문자열의 값을 튜플로 만들어서
        # value 변수에 저장하고 리턴을 해주면 된다.
        value = (self.index, self.data[self.index])
        self.index += 1    # 인덱스 증가
        return value

if __name__ == "__main__":
    for index, letter in MyEnumerate("abc"):
        print(index, ":", letter)


