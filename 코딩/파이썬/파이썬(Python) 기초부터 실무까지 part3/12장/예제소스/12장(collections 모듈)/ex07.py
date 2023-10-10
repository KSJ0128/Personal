# 이번 예제는 함수를 이용하여 각 알파벳의 글자의 수를 세어서 키로 저장을 하고
# 단어는 값으로 저장하는 딕셔너리를 리턴하는 코드를 보자.(list 를 이용)

from collections import defaultdict
# words 라는 리스트를 받아서 길이를 키로 하고 값을 리스트 값으로 하는 딕셔너리
# 리턴하는 함수
def counterWords(words):
    grouper = defaultdict(list)
    print(grouper)
    for word in words:
        # word 의 길이를 구하여 그 길이를 키로 하고 word 의 내용을 값으로 하고
        # 있다.
        length = len(word)
        grouper[length].append(word)
    return grouper
    
if __name__ == "__main__":
    li1 = ["감자", "귤", "사과", "배", "오징어", "꼼장어", "불가사리"]
    dic1 = counterWords(li1)
    print(dic1)
    print(dic1[2])