# defaultdict 모듈은 딕셔너리의 요소를 생성할 때, 키에 기본 값을 지정하는
# 방법이다.

# 일반적인 딕셔너리를 생성하고 키의 값으로 값을 알아낼 수가 있다.
dic = dict()
print(dic)
# 비어진 딕셔너리에 "a"라는 키는 없다는 오류가 발생한다.
# print(dic["a"])
print(dic.get("a"))

from collections import defaultdict
# defaultdict 의 아직 모르는 모든 키에 대해서 기본 값을 0으로 정하겠다.
dic = defaultdict(lambda : 0)   # lambda 를 이용하여 0을 리턴하게 만듬
print(dic["a"])
print(dic["b"])
print(dic[100])
print(dic)

print("----------------------------")
dic.clear()
dic = defaultdict(int)     # 키에 대한 값을 int 형으로 설정하였다.
dic["a"] += 100            # 해당 키에 대한 값에다가 연산을 할 수도 있다.
print(dic["a"])
print(dic["b"])
print(dic[100])
print(dic)


print("----------------------------")
dic.clear()
dic = defaultdict(float)     # 키에 대한 값을 float 형으로 설정하였다.
print(dic["a"])
print(dic["b"])
print(dic[100])
print(dic)

print("----------------------------")
dic.clear()
dic = defaultdict(str)     # 키에 대한 값을 str 형으로 설정하였다.
print(dic["a"])
print(dic["b"])
print(dic[100])
print(dic)