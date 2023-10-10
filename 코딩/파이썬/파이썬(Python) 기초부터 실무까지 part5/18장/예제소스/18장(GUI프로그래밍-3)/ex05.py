# 이벤트가 발생하면 메시지 박스가 보여지는 예제

from tkinter import *
from tkinter import messagebox
# 이벤트 처리함수 정의
# 사용자가 입력한 내용을 가져와서 messagebox 를 띄우는 함수
def click(event):
    test = entry.get()
    messagebox.showinfo("name", test)

window = Tk()
entry = Entry(window)
entry.pack(side=LEFT, padx=5)
button = Button(window, text="확인")
button.pack(side=LEFT)
# 버튼을 바인딩 처리
button.bind("<Button-1>",click)

window.mainloop()

