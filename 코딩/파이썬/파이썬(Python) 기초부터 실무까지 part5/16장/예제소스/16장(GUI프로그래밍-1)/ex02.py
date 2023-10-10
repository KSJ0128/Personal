# 버튼 위젯 실습
from tkinter import *

window = Tk()    # 루트 윈도우 생성함

# 버튼만 생성한 것 뿐이다.
button = Button(window, text="클릭하세요", bg="yellow", fg="blue",
                width=80, height=20, font="고딕 20")
# 루트 윈도우에 배치가 되어진다.
button.pack()
window.mainloop()
