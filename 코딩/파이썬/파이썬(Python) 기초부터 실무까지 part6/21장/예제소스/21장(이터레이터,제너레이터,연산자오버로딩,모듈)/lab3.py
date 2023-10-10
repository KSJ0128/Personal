# 문제3
# 호출될 때마다 앞의 수에 1을 더해서 반환하는 함수를 작성해보자.range()와 아주
# 유사하지만 이 함수는 상한값이 없다. 함수는 제너레이터를 이용하여 구현된다.
# -------------------------------------------------------------------
# 풀이
import time
# 앞의 수에 1씩 더해서 그 값을 보내는 제너레이터 형태의 함수 정의
def inf_sequence():
    num = 0
    while True:
        yield num
        # CPU 빨리 실행되기 때문에 눈으로 확인하기 힘들어서 sleep()를 이용함
        time.sleep(0.5)
        num += 1

if __name__ == "__main__":
    for n in inf_sequence():
        print(n, end=" ")