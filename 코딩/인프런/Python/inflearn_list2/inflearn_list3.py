# call by value, call by referation의 차이

def func(x):
    print('x = ', x, 'address = ', id(x))
    x += '하세요'
    print('x = ', x, 'address = ', id(x))

y = 10 # 정수형: 변경 불가능한 객체 -> call by value만 가능
y = '안녕' # 문자열: 변경 불가능한 객체 -> call by value만 가능
print('y = ', y, 'address = ', id(y))
func(y) # 함수 호출(call by value)
print('y = ', y, 'address = ', id(y))

print('------------------------------------')
def func_list(x):
    print('x = ', x, 'address = ', id(x))
    x.append("하세요")
    print('x = ', x, 'address = ', id(x))

y = [10, 20, 30] # 리스트: 변경 가능한 객체, call by referation 가능
print('y = ', y, 'address = ', id(y))
func_list(y) # 함수 호출(call by value)
print('y = ', y, 'address = ', id(y))