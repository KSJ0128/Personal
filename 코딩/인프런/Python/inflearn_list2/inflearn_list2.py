# 깊은 복사: 주소값 공유X, 원본에 영향X. 새로운 리스트 객체 생성해 새로운 주소값 할당.
# 세 가지의 방법이 있다.
scores  = [10, 20, 30, 40, 50]

# 깊은 복사기 때문에 원본 리스트와 복사된 리스트의 주소값이 다르다.
refer = list(scores)
print('scores의 주소값: ', id(scores))
print('refer의 주소값: ', id(refer))

refer[0] = 100
refer.append(-500)
refer.insert(2, -123)
print('scores의 주소값: ', id(scores))
print('refer의 주소값: ', id(refer))

# 원본 리스트와 복사된 리스트의 요소들이 다르다.
print('scores의 요소값: ', scores)
print('refer의 요소값: ', refer)
print('------------------------------------------------')

import copy # copy와 deepcopy 동일.

scores_copy = [10, 20, 30, 40, 50, -10]
refer_copy = copy.deepcopy(scores)
print('scores_copy의 주소값: ', id(scores_copy))
print('refer_copy의 주소값: ', id(refer_copy))

refer_copy[0] = 100
refer_copy.append(-500)
refer_copy.insert(2, -123)
print('scores_copy의 주소값: ', id(scores_copy))
print('refer_copy의 주소값: ', id(refer_copy))

print('scores_copy의 요소값: ', scores_copy)
print('refer_copy의 요소값: ', refer_copy)
print('------------------------------------------------')

scores_index = [10, 20, 30, 40, 50, -10]
refer_index = scores[:]
print('scores_index의 주소값: ', id(scores_index))
print('refer_index의 주소값: ', id(refer_index))

refer_index[0] = 100
refer_index.append(-500)
refer_index.insert(2, -123)
print('scores_index의 주소값: ', id(scores_index))
print('refer_index의 주소값: ', id(refer_index))

print('scores_index의 요소값: ', scores_index)
print('refer_index의 요소값: ', refer_index)