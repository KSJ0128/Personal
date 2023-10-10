# 중첩 루프(nested loop, 더블 루프)에 대한 실습
# 중첩 루프은 반복문안에 또 다른 반복문이 들어가 있는 형태를 말한다.
# 중요하게 기억해야할 것은 내부 반복문은 외부 반복문이 한 번 반복할 때마다
# 새롭게 실행해야 된다는 점이다.(중요)
# 이 중첩 루프는 테이블(표)와 비슷한 형태를 출력하고자 할 때 사용하면 아주 좋다.
# 2차원 형태로 나타내어질 수 있다.
# * 로 사각형 만들기

for y in range(5):
    for x in range(10):
        print("*", end="")
    print("")