# 색상에 대한 실습
from tkinter import *
from tkinter import colorchooser

window = Tk()
button = Button(window, text="버튼을 클릭하세요.")
button.pack()
# 속성값의 변경을 통하여 버튼의 배경색, 전경색을 바꾸는 방식
# 1.실제 색상 원색
# button["fg"] = "yellow"
# button["bg"] = "green"
# 2.16진수를 이용하여 색상을 변경
# button["fg"] = "#4287f5"
# button["bg"] = "#254194"

# tkinter.colorchooser 모듈의 askcolor() 를 호출하면 대화상자를 통해서
# 색상의 값을 입력 받을 수 있다.
# askcolor() 메서드는 튜플을 리턴하므로 해당하는 16진수의 값이 인덱스로 1번째
# 에 존재하므로 아래와 같이 설정할 수 있다.
color = colorchooser.askcolor()
print(color)
button["fg"] = color[1]

color = colorchooser.askcolor()
print(color)
button["bg"] = color[1]

window.mainloop()