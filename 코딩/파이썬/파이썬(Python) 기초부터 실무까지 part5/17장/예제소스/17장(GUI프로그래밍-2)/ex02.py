# 레이블에 이미지와 텍스트를 동시에 나타내기

from tkinter import *

window = Tk()
# window.geometry("800x1200")
# PhotoImage 클래스는 jpg 확장자를 지원을 하지 않는다.
photo = PhotoImage(file="images/w2.gif")
# 이미지는 들어가있는 레이블은 윈도우의 우측 배치
lbl1 = Label(window, image=photo)

# lbl1.photo = photo
lbl1.pack(side=RIGHT)
msg = """삶이 그대를 속일지라도 슬퍼하거나 노하지 말라 ! 우울한 날들을 견디면 : 믿으
라,기쁨의 날이 오리니.마음은 미래에 사는 것 현재는 슬픈 것: 모든 것은 순간적인 것, 지나가
는 것이니 그리고 지나가는 것은 훗날 소중하게 되리니."""

# 텍스트를 출력
lbl2 = Label(window,
                    justify=LEFT,   # 텍스트를 왼쪽정렬
                    padx=10,
                    text=msg)
lbl2.pack(side=LEFT)
window.mainloop()
