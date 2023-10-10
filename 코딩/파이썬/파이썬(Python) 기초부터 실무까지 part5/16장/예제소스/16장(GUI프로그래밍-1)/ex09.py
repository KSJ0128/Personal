# 여러 배치관리자 혼용하여 실습하기
from tkinter import *

window = Tk()
# 가로 600픽셀 세로 100픽셀의 크기를 가지는 윈도우이다.
window.geometry("600x100")
# Frame 은 위젯이긴 하나 단순위젯 아니고 컨테이너 위젯이다.
# 루트 윈도우 안에 프레임을 만든다.
frame = Frame(window)

# 버튼 3개를 프레임 안에 생성하고 배치한 것이다.
button1 = Button(frame, text="버튼 #1", bg="red", fg="white", width=10, height=2)
button2 = Button(frame, text="버튼 #2", bg="green", fg="black",width=10, height=2)
button3 = Button(frame, text="버튼 #3", bg="orange", fg="white", width=10, height=2)
button1.pack(side=LEFT)
button2.pack(side=LEFT)
button3.pack(side=LEFT)

label = Label(window, text="이 레이블은 버튼들 위에 배치가 됩니다.")
# 레이블은 루트 윈도우에 압축 배치관리자로 배치가 된다.
label.pack()
# 프레임도 루트 윈도우에 압축 배치관리자로 배치가 된다.
frame.pack()
window.mainloop()