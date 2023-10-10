# Canvas 의 메서드
# coords() : 좌표를 변경하는 메서드
# itemconfig() : 색상을 변경하는 메서드
# delete() : 선, 도형 등을 삭제하는 메서드

from tkinter import *

window = Tk()
# window.geometry("700x700")
canvas = Canvas(window, width=500, height=500, bg="white")
canvas.pack()

line1 = canvas.create_line(0, 0, 500, 500, fill="BLUE")
line2 = canvas.create_line(0, 500, 500, 0, fill="RED", width=5)

# line1 에 좌표를 변경한다.
canvas.coords(line1, 250, 250, 500, 500)

# line2 에 색상을 변경한다.
canvas.itemconfig(line2, fill="orange")

rect1 = canvas.create_rectangle(50,50,200,200,fill="yellow")
rect2 = canvas.create_rectangle(200,200,300,400,fill="red",outline="blue",width=10)

# rect1 을 삭제해보기
canvas.delete(rect1)

# 캔버스에 그려진 선, 도형을 다 삭제하기
canvas.delete(ALL)

# 사각형에 내접한 원 그리기
canvas.create_arc(10, 10 ,300, 300, extent=90, fill="red", outline="yellow", width=5)
# 타원 그리기
canvas.create_oval(50, 50, 250 , 350)
# 다각형 그리기
canvas.create_polygon(10,10, 150,110, 250, 20, fill="blue")
# 글자 나타내기
canvas.create_text(100,350, text="안녕하세요", font=("고딕 15 bold"))

window.mainloop()
