# 캔버스에 마우스 이벤트를 이용하여 선 그리기 실습

from tkinter import *

root = Tk()
canvas = Canvas(root, width=500, height=500, bg="white")

def draw(event):
    global x, y
    # 선을 그린다.
    canvas.create_line(x, y, event.x, event.y)
    # x, y의 값을 이벤트가 발생될 때 마다 계속 좌표를 저장을 해야지 그림이 그려진다.
    x, y = event.x, event.y

def down(event):
    global x, y
    # 전역변수 x, y를 클릭한 부분의 좌표로 초기화(한번만)
    x, y = event.x, event.y

def up(event):
    global x, y
    if (x, y) == (event.x, event.y):
        canvas.create_line(x, y, x+1, y+1)

canvas.bind("<B1-Motion>", draw)
canvas.bind("<Button-1>", down)
canvas.bind("<ButtonRelease-1>", up)
canvas.pack()

root.mainloop()