# 함수 만들어 스택 사용
def push(list, data):
    list.append(data)

def pop(list):
    if len(list) > 0:
        return list.pop()
    else: 
        print('스택이 비었습니다.')
        return

if __name__ == "__main__":
    list = [10, 20, 30, 40, 50]
    pop(list)
    pop(list)   
    pop(list)
    
    push(list, 70)
    push(list, 90)
    
    print(list)