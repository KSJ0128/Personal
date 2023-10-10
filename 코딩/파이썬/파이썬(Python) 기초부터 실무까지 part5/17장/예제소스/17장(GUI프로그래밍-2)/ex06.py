# 텍스트 위젯 : 멀티 라인 텍스트 영역에 사용하는 것, 타언어에서는
# TextArea 라고 호칭한다.텍스트 편집기 등에 이용한다.
from tkinter import *

window = Tk()
# 텍스트 위젯 인스턴스 생성
# width 의 값은 숫자나 알파벳은 1자리, 한글은 2자리를 차지한다.
t = Text(window, height=50, width=100)
t.pack()
# END 매개변수는 텍스트를 끝부분에 추가할 것을 의미하는 것이다.
t.insert(END, "텍스트 위젯은 여러 줄의 \n텍스트를 표시할 수 있습니다.")

window.mainloop()