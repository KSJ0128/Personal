# 리스트 복사하기
# 깊은 복사(deep copy) : 주소값을 공유하는 얕은 복사가 아니라 새로운 리스트 객체를
# 생성해서 새로운 주소값이 할당이 되어 원본 리스트 객체에는 전혀 영향을 끼치지 아니한다.
# 아래와 같이 3가지 방법으로 만든 리스트가 새로운 객체가 된다.
# 하여 깊은 복사가 진정한 복사의 방법이다.

# 첫 번째 방버 : list()메서드를 이용하는 방법
scores = [10,20,30,40,50]
refer = list(scores)
print("scores 의 주소값 : ", id(scores))
print("refer 의 주소값 : ", id(refer))
refer[0] = 100
refer.append(-500)
refer.insert(2, -123)

print("scores 의 주소값 : ", id(scores))
print("refer 의 주소값 : ", id(refer))

print("scores 의 요소값 : ", scores)
print("refer 의 요소값 : ", refer)
print("-------------------------")

import copy
# 2번째 방법 : copy 모듈에 있는 deepcopy(), copy()를 이용하는 방법
scores_copy = [10,20,30,40,50,-10]
# refer_copy = copy.deepcopy(scores)
refer_copy = copy.copy(scores)
print("scores_copy 의 주소값 : ", id(scores_copy))
print("refer_copy 의 주소값 : ", id(refer_copy))
refer_copy[0] = 100
refer_copy.append(-500)
refer_copy.insert(2, -123)

print("scores_copy 의 주소값 : ", id(scores_copy))
print("refer_copy 의 주소값 : ", id(refer_copy))

print("scores_copy 의 요소값 : ", scores_copy)
print("refer_copy 의 요소값 : ", refer_copy)
print("-------------------------")

# 3번째 방법 : [:] 인덱스를 이용하여 깊은 복사를 하는 방법
scores_index = [10,20,30,40,50,-10,-111]
refer_index = scores[:]
print("scores_index 의 주소값 : ", id(scores_index))
print("refer_index 의 주소값 : ", id(refer_index))
refer_index[0] = 100
refer_index.append(-500)
refer_index.insert(2, -123)

print("scores_index 의 주소값 : ", id(scores_index))
print("refer_index 의 주소값 : ", id(refer_index))

print("scores_index 의 요소값 : ", scores_index)
print("refer_index 의 요소값 : ", refer_index)
print("-------------------------")


