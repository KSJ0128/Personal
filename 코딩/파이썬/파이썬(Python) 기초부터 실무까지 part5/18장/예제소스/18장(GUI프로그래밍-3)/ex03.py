# 마우스 단일클릭과 더블클릭에 대한 실습

from tkinter import *

# 이벤트 처리 함수 정의
def one_click(event):
    print("단일 클릭, 왼쪽 버튼")

def double_click(event):
    print("더블 클릭, 왼쪽 버튼")

button = Button(None, text="마우스 클릭")
# 버튼에 이벤트 바인딩 처리
button.bind("<Button-1>", one_click)
# 더블클릭의 타입은 <Double-1>로 지정을 해주어야 한다.
button.bind("<Double-1>", double_click)
button.pack()
button.mainloop()
