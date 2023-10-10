# 레이블의 색상과 폰트를 변경하기 실습
from tkinter import *

window = Tk()
Label(window,
            text="고딕체 폰트와 빨간색을 사용합니다.",
            fg="red",
            font="고딕체 32 bold italic").pack()
Label(window,
            text="궁서체 폰트와 파란색을 사용합니다.",
            fg="blue",
            font="궁서체 32 bold italic").pack()
window.mainloop()

