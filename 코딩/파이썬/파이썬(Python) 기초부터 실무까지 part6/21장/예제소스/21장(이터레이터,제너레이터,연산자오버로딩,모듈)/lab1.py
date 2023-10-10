# 문제1
# 피보나치 이터레이터 만들기
# 피보나치 수열이란 앞의 두 수를 합하여 바로 뒤의 수가 되는 수열을 의미한다.
# 출력결과
# 1 1 2 3 5 8 13 21 34 ......
# 풀이
class Fibiterator(object):
    def __init__(self, a=1, b=0, maxValue=50):
        self.a = a
        print("생성자 self.a", a)
        self.b = b
        self.maxValue = maxValue
    def __iter__(self):
        return self
    def __next__(self):
        n = self.a + self.b
        if n > self.maxValue:
            raise StopIteration
        self.a = self.b
        # print("self.a : ", self.a, "self.b : ", self.b)
        self.b = n
        # print("self.a : ", self.a, "n : ", n)
        return n

if __name__ == "__main__":
    for n in Fibiterator():
        print(n, end=" ")

