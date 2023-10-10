# 람다식(무명함수, 익명함수)은 이름이 없는 함수를 만드는 방법을 말한다.이름은 없고
# 몸체만 존재하는 함수이다.람다식은 def 키워드를 사용하지 아니한다.아울러 return
# 키워드도 사용하지 아니한다.

# 람다식을 이용한 간단한 더하기 기능
f = lambda x, y : x + y         # 람다함수를 정의
print("정수의 합 : ", f(10,100))
print("정수의 합 : ", f(10,50))
print("------------------------")

# 위의 식을 일반함수로 만든다면 아래와 같다.
def get_sum(x, y):
    return x + y
print("정수의 합 : ", get_sum(10,100))
print("정수의 합 : ", get_sum(10,50))
