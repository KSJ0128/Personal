# 간단한 이벤트 처리에 대한 실습
# tkinter 프로그램은 이벤트에 기반을 두고 동작이 된다.
# 이벤트 : 근원지, 리스너, 이벤트핸들러(함수, 콜백함수)로 3가지로 구성
# 이벤트 핸들러를 등록하기 위해서 Button 의 생성자의 매개변수 command 에
# 함수명을 지정을 해주면 된다.

from tkinter import *

# 콜백함수 정의
def callback():
    button["text"] = "버튼이 클릭되었음"

window = Tk()
# 버튼을 생성할 때 버튼을 클릭하는 이벤트가 발생하면 callback 함수가 실행된다.
button = Button(window, text="클릭", command=callback)
button.pack(side=LEFT)
window.mainloop()