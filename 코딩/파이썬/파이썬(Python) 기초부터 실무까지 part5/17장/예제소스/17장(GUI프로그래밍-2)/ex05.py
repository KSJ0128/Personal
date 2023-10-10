# 엔트리 위젯(타 언어에서는 TextField) : 사용자가 데이터를 입력할 수 있도록 해주는
# 위젯이다.
from tkinter import *

def show():
    print("이름 : %s\n나이 : %s" % (e1.get(), e2.get()))

window = Tk()
Label(window, text="이름").grid(row=0, column=0)
Label(window, text="나이").grid(row=1, column=0)

# 엔트리 객체 만들기
e1 = Entry(window)
e2 = Entry(window)
e1.grid(row=0, column=1)
e2.grid(row=1, column=1)

# 버튼 생성
# window.quit 은 윈도우 창을 닫을 때 사용하는 메서드
# sticky 속성은 버튼의 주어진 기본배치값(중앙정렬)을 다른 정렬로 바꿀때 사용한다.
Button(window, text="종료", command=window.quit).grid(row=2, column=0, sticky=W, pady=5)
Button(window, text="보이기", command=show).grid(row=2, column=1, sticky=W, pady=5)

window.mainloop()