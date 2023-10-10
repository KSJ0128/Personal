# mutable object 중 dictionary 라는 타입이 있다.
# 딕셔너리라는 타입의 형태는 키와 값의 쌍으로 이루어져 있다.
# 딕셔너리의 키의 값은 유니크한 값이 되어야 한다.하지만 값은 변경이 가능하다.
# 딕셔너리의 call by reference 가 성립되는 이유는 변경 가능한 mutable object 이
# 기 때문에 가능한 것이다. call by objective-reference 라고도 칭한다.

def change(dic):
    print("change()함수 내의 연산전의 dic 의 값 : ", dic)
    print("change()함수 내의 연산전의 dic 의 주소값 : ", id(dic))
    dic["몸무게"] = 42
    print("change()함수 내의 연산후의 dic 의 값 : ", dic)
    print("change()함수 내의 연산후의 dic 의 주소값 : ", id(dic))

dic = {"name":"신은혁", "age":14, "height":160}
# print(dic)
# 키를 주고 값을 얻어온다.
# print(dic["name"])
print("호출 전의 dic 의 값 : ", dic)
print("호출 전의 dic 의 주소값 : ", id(dic))
change(dic)
print("호출 후의 dic 의 값 : ", dic)
print("호출 후의 dic 의 주소값 : ", id(dic))