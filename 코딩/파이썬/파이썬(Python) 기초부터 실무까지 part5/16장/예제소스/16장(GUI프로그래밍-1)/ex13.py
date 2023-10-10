# 유연한 격자 배치관리자를 실습해보기
from tkinter import *

window = Tk()

# 레이블 생성
Label(window, text="너비").grid(row=0)
Label(window, text="높이").grid(row=1)

# 엔트리 생성
e1 = Entry(window)
e2 = Entry(window)

e1.grid(row=0, column=1)
e2.grid(row=1, column=1)

# 이미지를 가진 레이블을 생성하여 2열과 2행에 걸쳐서 표식한다.
photo = PhotoImage(file="apple.gif")
label = Label(window, image=photo)
# 이미지를 셀들의 병합으로 나타내고 있다.
label.grid(row=0, column=2, columnspan=2, rowspan=2)

# 첫 번째 버튼 2열에 걸쳐서 표식한다.
Button(window, text="이미지 저장").grid(row=2, column=0, columnspan=2)
# 두 번째, 세 번째 버튼을 2열과 3열 표식한다.
Button(window, text="확대").grid(row=2, column=2)
Button(window, text="축소").grid(row=2, column=3)


window.mainloop()