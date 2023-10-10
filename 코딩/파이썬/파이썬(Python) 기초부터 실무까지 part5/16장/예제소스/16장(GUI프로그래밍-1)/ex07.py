# 단순위젯 : Entry 위젯
# Entry 위젯 : 사용자가 키보드로 입력한 내용을 전달하는 위젯, 예를 들면 아이디나
# 패스워드 등 get() 를 사용하면 입력한 내용을 가져올 수가 있다.
# 사용자의 입력을 삭제하려면 delete() 사용한다.

from tkinter import *

window = Tk()
window.title("엔트리 위젯 실습")
# 루트윈도의 크기를 설정하는 방법
window.geometry("400x200")
# Entry 위젯은 height 속성은 없다.
entry = Entry(window, fg="black", bg="yellow", width=80)
entry.pack()

window.mainloop()