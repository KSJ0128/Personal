# 자료 구조: 데이터의 특징을 고려해 데이터를 저장하는 방법
# 최대한 메모리를 효율적으로 저장 및  반환하는 방법으로, 데이터를 관리
# 대용량일수록 빨리 저장하고 빨리 검색, 메모리 최대한 효율적으로 사용해 유저에게 빠른 피드백

# 스택(stack): LIFO(Last In First Out)
# 데이터 저장: push, 데이터 삭제: pop
# append로 push 구현
stack_data = []
stack_data.append(10) 
stack_data.append(20)
stack_data.append(30)
stack_data.append(40)
stack_data.append(50)
print(stack_data)

# pop으로 pop 구현
stack_data.pop() # 인덱스 지정 안하면 마지막 인덱스 값 삭제
stack_data.pop()
stack_data.pop()
print(stack_data)

# 입력 받은 텍스트 역순 추출
word = input("문자열 입력해주세요: ")
word_list = list(word) # 문자열 한 글자씩 리스트에 저장

result = []
for _ in range(len(word_list)):
    result.append(word_list.pop())

print(result)
