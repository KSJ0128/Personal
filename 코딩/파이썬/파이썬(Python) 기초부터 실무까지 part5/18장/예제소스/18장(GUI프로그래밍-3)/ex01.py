# 이벤트 처리에 대한 슬라이드에 있던 코드 실습
# 지금까지는 command 속성을 이용하여 이벤트 처리를 했다면
# bind()를 이용하여 이벤트 처리를 해보도록 하자.
# 문법 : 위젯.bind(이벤트지정자, 이벤트 처리 함수)

from tkinter import *

window = Tk()
# 이벤트 처리함수 정의
def callback(event):
    print(event.x, event.y, "에서 마우스 이벤트 발생")

frame = Frame(window, width=200, height=200)
# frame 에 이벤트를 등록하는 것
# 프로그램을 실행하고 마우스 왼쪽 버튼을 클릭했을 때, callback 함수가 실행
frame.bind("<Button-1>", callback)
frame.bind("<Button-2>", callback)  #<Button-2> 휠을 눌렀을때
frame.bind("<Button-3>", callback)  #<Button-3> 우클릭 했을때
frame.pack()
window.mainloop()


