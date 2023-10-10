# 이벤트 처리 실습 : 키 이벤트 실습
# focus_set() : 원하는 위젯으로 포커스를 이동시킬수 있는 메소드

from tkinter import *

window = Tk()

# 이벤트 처리 함수 정의
def key(event):
    print(repr(event.char), "가 눌렸습니다.")

def callback(event):
    # 함수가 실행되면 키보드 포커스를 소유하고 있는 위젯
    frame.focus_set()
    print(event.x, event.y, "에서 마우스 이벤트 발생")

frame = Frame(window, width=200, height=200)
# frame 에 2개의 바인딩 처리
frame.bind("<Key>", key)
frame.bind("<Button-1>", callback)
frame.pack()
window.mainloop()