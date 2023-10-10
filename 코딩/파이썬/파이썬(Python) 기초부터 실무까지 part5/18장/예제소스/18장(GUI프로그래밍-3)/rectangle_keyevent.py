# 사각형을 만들어서 방향키로 움직이기 실습

from tkinter import *

# 이벤트 함수들 정의
# 1.좌측 방향키를 눌렀을 때
def left(event):
    print("left")
    # Canvas 클래스에 있는 move()는 객체가 움직이게 만들고자 할 때
    # 사용한다. 매개변수로 첫 번째 이동할 객체, 좌우로 움직임(음:좌측
    # ,양:우측), 위아래 움직임(음:위로, 양:아래)
    canvas.move(rect, -5, 0)
# 2.우측 방향키를 눌렸을 때
def right(event):
    print("right")
    canvas.move(rect, 5, 0)

# 3.아래 방향키를 눌렸을 때
def down(event):
    print("down")
    canvas.move(rect, 0, 5)

# 4.위의 방향키를 눌렸을 때
def up(event):
    print("up")
    canvas.move(rect, 0, -5)

root = Tk()
canvas = Canvas(root, bg="white", width=500, height=500)
canvas.pack()
rect = canvas.create_rectangle(100,100,200,200, fill="red")

# 키 바인딩 처리
# 키 이벤트를 발생시키기 위해서는 반드시 focus_set() 를 호출하여 키보드
# 의 포커스를 가져와야 한다.
canvas.focus_set()
canvas.bind("<Left>", left)
canvas.bind("<Right>", right)
canvas.bind("<Up>", up)
canvas.bind("<Down>", down)

root.mainloop()