# Label 에 대한 실습
# Label 위젯에 이미지 표시하기 실습

from tkinter import *

window = Tk()
# 이미지 인스턴스를 생성하여 photo 변수에 저장
photo = PhotoImage(file="images/a1.gif")
lbl = Label(window, image=photo)
# 이미지 객체를 레이블에서 참조를 얻는 것이다.
# lbl.photo = photo
lbl.pack()

window.mainloop()