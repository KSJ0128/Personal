import numpy as np
arr1 = np.array([0, 2, 5.5, 7]) #dtype: float // 출력시 값 뒤에 . 붙음
print(arr1)
print("-----------------------------------------------------")

arr2 = np.array([[1,2,3],[4,5,6]]) #dtype: int
print(arr2)
print("-----------------------------------------------------")

print(type(arr1))
print(arr2.dtype)
print("-----------------------------------------------------")

arr = np.zeros(5) # 0으로 초기화된 1차원 넘파이 배열 생성, dtype: float
print(arr)
print(type(arr))
print(arr.shape) # 5,1
print(arr.dtype)
print("-----------------------------------------------------")

arr = np.zeros(shape=(6,2)) 
print(arr)
print(arr.dtype)
for i in range(6):
    arr[i] = (i,i) 
print(arr)
print("-----------------------------------------------------")

arr1 = np.zeros(5)
print(arr1.dtype)
arr2 = np.ones(5) 
print(arr2.dtype)
arr3 = np.empty(5) # random initialize?
print(arr3.dtype)
print(arr3) 
print("-----------------------------------------------------")

arr = np.empty((2,2))
print(arr)
arr = np.empty((2,2), dtype=int) 
print(arr)
print("-----------------------------------------------------")

arr = np.eye(5) # 대각선 1, 나머지 0
print(arr)
print(arr.dtype) # float
print("-----------------------------------------------------")

arr = np.linspace(2.0, 3.0, num=5) # 구간 내 숫자 채우기, 균일
print(arr)

arr = np.linspace(2.0, 3.0, num=5, endpoint=False) # 데이터 뒤에 . 없애기
print(arr)
print("-----------------------------------------------------")

arr = np.zeros([2,3])
arr = arr.reshape(-1) # 행 1로 고정
print(arr)
print("-----------------------------------------------------")

arr = arr.reshape(-1, 1) # 열 1로 고정
print(arr)
print("-----------------------------------------------------")

arr = arr.reshape(3, -1) # 행 3으로 고정
print(arr)
print("-----------------------------------------------------")

# arr = arr.reshape(7, -1) 초기화된 데이터의 개수가 6개인데 이를 초과하므로 실행 불가
# print(arr)

arr = arr.reshape(2, 1, -1) # z, x, y 순?
print(arr)
print("-----------------------------------------------------")

arr = np.arange(24).reshape(2, 3, 4) # reshape 구성요소를 곱한 값이 데이터 개수와 같아야 한다.
print(arr)
print("-----------------------------------------------------")

arr = np.array([[[0,  1,  2,  3],
                [4,  5,  6,  7],
                [8,  9, 10, 11]],
                [[12, 13, 14, 15],
                [16, 17, 18, 19],
                [20, 21, 22, 23]]])
print(arr.ndim) # 배열의 차원
print(arr.shape) # 배열의 크기
print(arr.size) # 배열의 데이터 개수
print(arr.dtype) # 배열 데이터의 타입
print(arr.itemsize) # 배열 요소 하나의 크기(바이트 단위) 
# int64 -> 8, float32 -> 4 // 나누기 8한 값
print(arr.strides) # 차원을 건너뛸 때 필요한 바이트 크기
# y: 열, itemsize * 1
# x: 행, itemsize * 행의 item 개수
# z: 차원, itemsize * 행의 item 개수 * 행의 개수
print("-----------------------------------------------------")

print(np.eye(N =  3, k = 1)) # N: 행렬의 크기, k: 주대각선에서 얼마나 떨어져있는지
print("-----------------------------------------------------")

arr = np.array([('jin', 25, 67), ('suho', 18, 77)], dtype=[('name', 'U10'), ('age', 'i4'), ('weight', 'f4')])
print(arr)
print(arr.dtype)
# ('name', 'U10'): 'name'이라는 필드의 데이터 타입. 
# 'U10'은 최대 길이가 10인 Unicode 문자열.
# ('age', 'i4'): 'age'라는 필드의 데이터 타입.
#  'i4'는 4바이트 크기의 정수 타입.
# ('weight', 'f4'): 'weight'라는 필드의 데이터 타입.
# 'f4'는 4바이트 크기의 부동 소수점 실수 타입.
print("-----------------------------------------------------")

print(arr['name'])
print(arr['age'])
print(arr['weight'])
print("-----------------------------------------------------")

# arr = np.array(object: [('iwillbeback', 25, 67), ('yourackmyworld', 18, 77)], dtype=[('name', 'U20'), ('age', 'i4'), ('weight', 'f4')])
# object..?

print(np.dtype([('a', 'f4'), ('b', np.float32), ('c', 'f4', (2,2))]))
print("-----------------------------------------------------")

#print(np.dtype({'names': ['col1', 'col2'], 'formats': ['i4', 'f4']}))
print(np.dtype({'names': ['col1', 'col2'], 'formats': ['i4', 'f4'],'offsets': [0, 4], 'itemsize': 12}))

d_c = np.dtype([('', 'f4'), ('', np.float32, (2,2)), ('', 'f4')])
print(d_c.fields)
print("-----------------------------------------------------")

def print_offsets(d):
    print("offsets:", [d.fields[name][1] for name in d.names]) 
    print("itemsize:", d.itemsize)
print_offsets(np.dtype('u1,u1,i4,u1,i8,u2')) 
d=np.dtype('u1,u1,i4,u1,i8,u2')
print(d)
print(d.itemsize)
print(d.fields) 
print(d.names)
print(d.fields['f0'])
print(d.fields['f0'][1]) 
print_offsets(np.dtype('u1,u1,i4,u1,i8,u2', align=True))
print("-----------------------------------------------------")

a = np.array([(1, 2, 3), (4, 5, 6)], dtype='i8, f4, f8')
a[1] = (7, 8, 9)
print(a)
print("-----------------------------------------------------")

a = np.zeros(2, dtype='i8, f4, ?, S1')
print(a)
a[:] = 7 # 숫자 부분 7로 초기화
print(a)
a[:] = np.arange(2) # 숫자 부분 0부터 1까지의 값으로 초기화
print(a)
print("-----------------------------------------------------")

a = np.zeros(3, dtype=[('a', 'i8'), ('b', 'f4'), ('c', 'S3')]) 
b = np.ones(3, dtype=[('x', 'f4'), ('y', 'S3'), ('z', 'O')]) 
print(a) # 숫자 부분 0으로 초기화
print(b) # 숫자 부분 1로 초기화
print(a.dtype)
print(b.dtype)
print("-----------------------------------------------------")

b[:] = a # 1을 0으로 초기화
print(b)
print(a)
print(a.dtype)
print(b.dtype)
print("-----------------------------------------------------")

arr1 = np.arange(10) # 0-9
print(arr1)
print(arr1[1])
print(arr1[-3:])
print("-----------------------------------------------------")

arr2 = np.arange(9).reshape(3,3) # 0-8
print(arr2)
print(arr2[2])
print(arr2[2, 1])
print("-----------------------------------------------------")

arr3 = np.reshape(np.arange(24), (2,3,4)) # 0-23
print(arr3)
print(arr3[1,1,2])
print(arr3[1,0:,0::2])
print(arr3[1][2][3])
print("-----------------------------------------------------")

print(arr1[1])       # Access the element at index 1
print(arr1[:6])      # Access elements from the beginning up to index 6 (exclusive)
print(arr1[0:5])     # Access elements from index 0 to 4 (inclusive)
print(arr1[::2])     # Access every 2nd element starting from the beginning
print(arr1[1::2])    # Access every 2nd element starting from index 1
print(arr1[1:7:2])   # Access every 2nd element from index 1 to 6 (inclusive)

print(arr1[-3:9])    # Access elements from index -3 to 8
print(arr1[:-3])     # Access elements from the beginning up to the 3rd-to-last element
print(arr1[-3:2:-1]) # Access elements from index -3 to 3 in reverse order

# Attempting to access elements in an invalid way
# print(arr1[5:2])   # This will result in an empty array

print(arr1[5:])      # Access elements from index 5 to the end
print(arr1[1:])      # Access elements from index 1 to the end
print("-----------------------------------------------------")

print(arr2[:2, :2])   # Access the top-left 2x2 subarray
print(arr2[:, ::-1])  # Reverse the order of columns

print(arr2[:, :])     # Access all elements
print(arr2[1, :])     # Access the entire second row
print(arr2[1, 2])
print("-----------------------------------------------------")

print(arr3[:2, 1:, :2])
print("-----------------------------------------------------")

arr = np.array([[0,   1,   2], [3,   4,   5], [6,   7,   8], [9,  10,  11]])
rows = np.array([[0, 0], [3, 3]], dtype=np.intp)
columns = np.array([[0, 2], [0, 2]], dtype=np.intp)
print(arr)
print(arr[rows, columns])
print("-----------------------------------------------------")

arr = np.arange(10)
print(arr.shape)
arr_row = arr[np.newaxis, :]
print(arr_row.shape)
arr_col = arr[:, np.newaxis]
print(arr_col.shape)
print("-----------------------------------------------------")

arr_col_1 = arr_col.T
print(arr_col_1)
print("-----------------------------------------------------")

arr1= np.array([1, 2, 3, 4, 5])
arr2 = np.array([11, 12, 13])
arr1_nx = arr1[:, np.newaxis]
arr2_nx = arr2[:, np.newaxis]
print(arr1_nx)
print(arr2_nx)
print("-----------------------------------------------------")

print(arr1_nx + arr2)
print(arr2_nx + arr1)
print("-----------------------------------------------------")

arr = np.arange(12).reshape(3,4)
print(arr)
ind = arr>5
print(ind)
print(arr[ind]) # ind 값 true인 것만 print
print("-----------------------------------------------------")

arr1 = np.arange(6).reshape(1, 2, 3)
print(arr1)
print("-----------------------------------------------------")

print(np.transpose(arr1, (1, 0, 2))) # transpose?
print("-----------------------------------------------------")

print(np.transpose(arr1, (1, 0, 2)).shape)