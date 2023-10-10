# 리스트 복사
# 얕은 복사: 주소값 공유, 원본에 영향을 끼친다.
scores  = [10, 20, 30, 40, 50]
refer = scores # 주소 공유
print('scores의 주소값: ', id(scores))
print('refer의 주소값: ', id(refer))
print('------------------------------------------------')

refer[0] = 100 # 100, 20, 30, 40, 50
refer.append(-70) # 100, 20, 30, 40, 50, -70
refer.insert(1, -100) # 100, -100, 20, 30, 40, 50, -70

# 수정해도 주소값의 변화X
print('scores의 주소값: ', id(scores))
print('refer의 주소값: ', id(refer))

# 원본 리스트와 복사된 리스트 모두 값이 변화됨.
print(scores)
print(refer)