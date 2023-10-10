# 탐색하기
# 주어진 데이터 내에서 어떠한 특정한 값을 찾는 행위가 탐색하는 것이다.
# index()를 이용하여 일반적인 탐색이 가능하다.
list_word = ["gold", "blue", "red", "yellow", "green"]
search_word = input("찾고자 하는 단어를 입력해주세요 : ")

if search_word in list_word:
    index = list_word.index(search_word)
    print("찾고자 하는 단어가",index,"인덱스에 존재합니다.")
else:
    print("찾고자 하는 단어가 없습니다.")

# 프로그래머가 직접 탐색을 하는 알고리즘을 구현해야 하는 경우도 상당히 많다.
# 탐색의 가장 기본적인 방법이 순차 탐색이다.
# 순차 탐색은 리스트의 요소를 순서대로 하나씩 꺼내서 탐색키 값과 비교해서 성공하면
# 루프를 빠져나오고 루프를 다 했음에도 없다면 탐색키가 존재하지 않음을 의미한다.

def number_search(list, key):
    cnt = 0
    for i in range(len(list)):
        if key == list[i]:    # 찾고자 하는 값이 리스트에 존재한다면...
            cnt += 1      # 같은 값이 존재하면 갯수를 증가하는 코드
    return cnt

# 같은 수가 존재한다면 그 갯수도 몇 개인지 출력하시오.
num_list = [10,20,30,40,50,50,50,50,50,60,70,80,90,100,100,100]
key = int(input("찾고자 하는 정수를 입력하세요 : "))
cnt = number_search(num_list, key)

if cnt == 0:        # cnt 가 0이라면 찾고자 하는 값이 존재하지 않는다.
    print(key,"은 존재하지 않습니다.")
else:               # 찾고자 하는 값이 해당 리스트에서 몇 개인지 확인해준다.
    print(key,"은 ",cnt , "개 존재합니다.")

# 모든 조건에 만족하는 항목을 전부 찾는 방법
result = []
for i in num_list:
    if i >= 50:
        result.append(i)
print(result)
# 문제
# 바로 위에 있는 코드를 사용자로부터 키를 입력받아서 키값 이상의 값들을 출력하고
# 그 키값 이상인 값들의 총 갯수를 구하는 프로그램을 작성해보시오.
