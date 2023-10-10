import numpy as np
import pandas as pd

# Create Series
# series = pd.Series(data, index = index)

idx_list = ['a', 'b', 'c', 'd']
value_t = np.random.randn(4) # 네 개의 난수 생성(평균이 0이고 표준 편차가 1인 분포)

ser = pd.Series(value_t, idx_list)
print(ser)
print("------------------------------------")
print(ser.values)
print("------------------------------------")
print(ser.index)
print("------------------------------------")

da = {'seoul' : 2000, 'busan' : 2500, 'daejeon' : 3000}
print(pd.Series(da))
print("------------------------------------")

da = {'a' : 0., 'b' : 1., 'c' : 2.}
print(pd.Series(da))
print("------------------------------------")

print(pd.Series(da, idx_list))
print("------------------------------------")

print(ser[:]) # ser 전체 출력
print(ser[1:]) # ser 1번 인덱스부터 출력
print(ser[:2]) # ser 2번 인덱스 전까지 출력
print(ser["a":"c"])  # ser 인덱스 a부터 인덱스 c까지 출력
print("------------------------------------")

# print(np.log(ser))
print("------------------------------------")

print(ser['a']) # 인덱스 a의 data만 출력
ser['d'] = 7 # 인덱스 d의 data = 7로 설정
print(ser)
print("------------------------------------")

print(ser + ser) # ser의 각 데이터 2배
print(ser * 2)
print("------------------------------------")

# 1번 인덱스와 4번 인덱스는 더해지는 값이 없기에 NaN으로 처리됨
print(ser[1:] + ser[:-1])
print("------------------------------------")

# 시리즈 객체 이름 설정
ser = pd.Series(np.random.randn(5),  name='seoul')
print(ser)

# 시리즈 이름 변경
ser1 = ser.rename('busan')
print(ser1.name)
print("------------------------------------")

d = {'one': pd.Series([1., 2., 3.],
                       index=['a', 'b', 'c']),
              'two': pd.Series([1., 2., 3., 4.],
                       index=['a', 'b', 'c', 'd'])}

d1 = [pd.Series([1., 2., 3.],
                       index=['a', 'b', 'c'], name="one"),
              pd.Series([1., 2., 3., 4.],
                       index=['a', 'b', 'c', 'd'], name="two")]

# 데이터 프레임에 담으면 인덱스가 열, name이 행
df = pd.DataFrame(d1)
print(df)
print(df.T)
print("------------------------------------")

df = pd.DataFrame(d, index = ["d","b","a"])
print(df)
df = pd.DataFrame(d, index = ["d","b","a"], columns=["two", "three"])
print(df)
print("------------------------------------")

print(df.index)
print(df.columns)
print("------------------------------------")

d = {'가': [1., 2., 3.],
              '나': [3., 2., 1.]}

df = pd.DataFrame(d, index=["a","b","c"])
print(df.가)
print("------------------------------------")

arr = np.zeros((2,), dtype=[('A', 'i4'), ('B', 'f4'), ('C', 'a10')])
arr[:] = [(1, 2., 'Hello'), (2, 3., 'World')]
print(arr)
print("------------------------------------")

# 행: x, 열: dtype
print(pd.DataFrame(arr))
print("------------------------------------")

# 행: index, 열: dtype
print(pd.DataFrame(arr, index=['first', 'second']))
print("------------------------------------")

# 행: x, 열: columns
print(pd.DataFrame(arr, columns=['C', 'A', 'B']))
print("------------------------------------")

df = pd.DataFrame({('a','b'): {('A','B'): 1, ('A','C'): 2},
                       ('a','a'): {('A','C'): 3, ('A','B'): 4},
                       ('a','c'): {('A','B'): 5, ('A','C'): 6},
                       ('b','a'): {('A','C'): 7, ('A','B'): 8},
                       ('b','b'): {('A','D'): 9, ('A','B'): 10}})
print(df)
print("------------------------------------")

# orient='index'
# 딕셔너리의 키를 행(row) 인덱스로 사용하도록 지정하는 옵션
df = pd.DataFrame.from_dict(dict([('A', [1, 2, 3]), ('B', [4, 5, 6])]),
                            orient='index', columns=['one', 'two', 'three'])

print(df)
print("------------------------------------")

d = {'one': pd.Series([1., 2., 3.],
                       index=['a', 'b', 'c']),
              'two': pd.Series([1., 2., 3., 4.],
                       index=['a', 'b', 'c', 'd'])}

df = pd.DataFrame(d)

print(df)
print("------------------------------------")

print(df['one'])

print(df['two'])
print("------------------------------------")

df['three'] = df['one'] * df['two']

df['flag'] = df['one'] > 2

print(df)
print("------------------------------------")

# del: 데이터프레임 열 삭제, drop: 데이터프레임 행 삭제
# del df['three']

df.pop('three')
print(df)
print("------------------------------------")

df1 = df.T

# 행을 지우려고 전치행렬 사용
del df1['a']
print(df1.T)
print("------------------------------------")

# ha라는 열 만들고 데이터 hiho로 초기화
df1['ha'] = 'hiho'

# c열 data 끌고오기
df1['hi'] = df1['c'][:2]

print(df1)
print("------------------------------------")

print(ser)
print(ser.drop(labels=[2,3]))
print("------------------------------------")

df1= pd.DataFrame(np.arange(12).reshape(3, 4),
                  columns=['A', 'B', 'C', 'D'])
print(df1)
print(df1.drop([1,2]))
print("------------------------------------")

# label 사용해 행 선택시 loc, 정수 인덱스 활용해 행 선택시 iloc 사용
print(df)
print(df.loc['b'])
print(df.iloc[2])
print("------------------------------------")

df = pd.DataFrame(np.random.randn(5, 4), columns=['A', 'B', 'C', 'D'])
df2 = pd.DataFrame(np.random.randn(3, 3), columns=['A', 'B', 'C'])
print(df + df2) # 더해지는 값이 없는 부분은 NaN으로 초기화
print("------------------------------------")

ser = pd.Series(['a', 'b', 'c', 'a'],
                    dtype='category')

print(ser)
print("------------------------------------")

ind = pd.date_range('1/1/2019', periods=5)
ser = pd.Series(np.random.randn(5), index=['a', 'b', 'c', 'd', 'e'])
df = pd.DataFrame(np.random.randn(5, 3), index=ind, columns=['A', 'B', 'C'])
print(ser)
print("------------------------------------")

print(df[2:])
print("------------------------------------")

df = pd.DataFrame({'one':pd.Series(np.random.randn(2),index=['a','b']),
                    'two':pd.Series(np.random.randn(3),index=['a','b','c']),
                    'three':pd.Series(np.random.randn(2),index=['b','c'])})
row = df.iloc[1] # == b
col = df['two']
print(df)
print("------------------------------------")

# 각 열의 row 행 데이터 초기화
print(df.sub(row, axis='columns'))
print("------------------------------------")

# col 열의 데이터 0으로 초기화
print(df.sub(col, axis=0))
print("------------------------------------")

d = {'one': [1., 2., np.nan],
        'two': [3., 2., 1.],
        'three': [np.nan, 1., 1.]}
df = pd.DataFrame(d, index=list('abc'))

print(df)
print("------------------------------------")

d1 = {'one': pd.Series([1.,2.], index=['a','b']),
        'two': pd.Series([1.,1.,1.], index=['a','b','c']),
        'three': pd.Series([2.,2.,2.], index=['a','b','c'])}
df1 = pd.DataFrame(d1)

# fill_value=0: NaN 값이 있을 경우 0으로 대체
print(df.add(df1, fill_value=0))
print("------------------------------------")

print(df)
print("------------------------------------")

# 0: 각 열의 평균, 1: 각 행의 평균
print(df.mean(0))
print(df.mean(1))

print("------------------------------------")

# 0: 각 열의 sum, 1: 각 행의 sum, skipna=True: NaN 값을 무시
print(df.sum(0, skipna=False))
print(df.sum(1, skipna=True))
print("------------------------------------")

ser = pd.Series(np.random.randn(500))
ser[20:500] = np.nan

ser[10:20] = 5

# Series 객체에서 고유한(unique)한 값을 가진 요소의 개수
# 최초의 값: 0 - 9번 인덱스, 5 / nan은 countX
print(ser.nunique())
print("------------------------------------")

ser = pd.Series(np.random.randn(1000))

# 짝수행 NaN으로 초기화
ser[::2] = np.nan

# describe(): percentiles 매개변수 전달해 특정 백분위수(percentiles) 값을 설정
# 0.05, 0.25, 0.65, 0.7, 0.8 및 0.99 백분위수를 계산
# 백분위수에 대한 요약 통계 정보를 생성
print(ser.describe(percentiles=[0.05, 0.25, .65, .7,.8 ,.99]))
print("------------------------------------")

# chatgpt
ser = pd.Series(['a','a','b','c','c',np.nan, 'c', 'd'])
print(ser.describe())
print("------------------------------------")

# chatgpt

df = pd.DataFrame({'a': ['Yes', 'Yes', 'No', 'No'], 'b': range(4)})
print(df.describe())
print("------------------------------------")

ser = pd.Series(np.random.randn(5))
print(ser)
print("------------------------------------")

# idxmin: ser 내 최솟값 가지는 인덱스
# idxmax: ser 내 최댓값 가지는 인덱스
print(ser.idxmin(), ser.idxmax())
print("------------------------------------")

# 0부터 6까지의 정수 중 30개의 난수 데이터를 생성
data = np.random.randint(0, 7, size=30)
ser1 = pd.Series(data)

# 각 값의 빈도를 계산하고 출력
print(ser1.value_counts())
# print(pd.value_counts(data))
print("------------------------------------")