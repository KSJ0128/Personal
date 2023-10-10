# tkinter 라는 모듈을 이용하여 GUI 프로그램 만들기
# tkinter 는 파이썬에서 그래픽 사용자 인터페이스(GUI)를 개발할 때
# 반드시 필요한 모듈이다.
from tkinter import *

window = Tk()   # 루트 윈도우를 생성
# 레이블 위젯을 생성한 것 뿐이다.
label = Label(window, text="Hello tkinter")
# 레이블 위젯을 윈도우에 배치해준다.
label.pack()
window.mainloop()  # 윈도우가 나타나면서 사용자의 동작(이벤트)대기