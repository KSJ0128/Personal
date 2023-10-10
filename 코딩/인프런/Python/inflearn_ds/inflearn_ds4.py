# 함수로 큐 구현해보기
def offer(list, data):
    list.append(data)

def poll(list):
    if len(list) > 0:
        return list.pop(0)
    else:
        print("큐가 비었습니다.")
        return False

if __name__ == "__main__":
    list = [10, 20, 30, 40, 50]
    offer(list, 60)
    offer(list, 70)
    poll(list)
    poll(list)
    poll(list)
    print(list)