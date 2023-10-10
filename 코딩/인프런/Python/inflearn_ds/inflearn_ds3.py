# 큐(queue): FIFO
# 데이터 삽입: offer, 데이터 삭제: poll

queue = []
queue.append(10)
queue.append(20)
queue.append(30)
queue.append(40)
queue.append(50)
print(queue)

# 큐는 FIFO기 떄문에 pop의 인덱스를 0으로 준다.
print(queue.pop(0))
print(queue.pop(0))

print(queue)

