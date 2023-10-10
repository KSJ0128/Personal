# 배치관리자(Layout Manager) : 위젯들을 윈도우에 배치하는 방법, 기본값은 수직으로
# 쌓는다.
from tkinter import *

window = Tk()
window.title("배치관리자")   # 윈도우의 타이틀 설정

button1 = Button(window, text="버튼1", bg="yellow", width=30, height=10)
button2 = Button(window, text="버튼2", bg="yellow", width=30, height=10)
button3 = Button(window, text="버튼3", bg="yellow", width=30, height=10)

# pack() 메서드 호출시 매개변수가 없는 것으로 호출을 하면 수직으로 정렬이 이루어진다.
# 그 이유는 side 의 값이 기본적으로 TOP 설정이 되어 있기 때문이다.
# button1.pack()
# button2.pack()
# side 매개변수의 값은 TOP, LEFT, RIGHT, BOTTOM 존재하므로 배치할 때 적절히 이용을
# 하면 된다.
# padx 는 가로로 안쪽 여백을 준다.pady 는 수직으로 위쪽 아래쪽에 안쪽 여백을 준다.
# 패안마바(패딩은 안쪽 여백, 마진은 바깥쪽 여백)
button1.pack(side=LEFT, padx=20, pady=20)
button2.pack(side=LEFT, padx=20, pady=20)
button3.pack(side=LEFT, padx=20, pady=20)

# 버튼의 text 속성을 바꾸는 방법
button1["text"] = "One"
button2["text"] = "Two"
button3["text"] = "Three"

window.mainloop()