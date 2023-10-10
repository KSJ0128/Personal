# 마우스 모션에 대한 실습

from tkinter import *
# 이벤트 처리 함수 정의
# 마우스가 움직이면 움직인 좌표값을 찍는다.
def motion(event):
    print("마우스의 위치 : (%s %s)" %(event.x, event.y))

window = Tk()
frame = Frame(window, width=500, height=500, bg="yellow")
# 마우스 모션 이벤트 처리 함수를 바인딩하고 있다.
frame.bind("<Motion>",motion)
frame.pack()
window.mainloop()