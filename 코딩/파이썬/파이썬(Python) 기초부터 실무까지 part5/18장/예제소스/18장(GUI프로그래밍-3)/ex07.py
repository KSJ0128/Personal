# 기능이 없는 메뉴를 생성하는 실습
from tkinter import *

root = Tk()
mainMenu = Menu(root)   # mainMenu 변수에 Menu 생성했다.소유자가 root 가 된다.
root.config(menu=mainMenu)  # 윈도우에 메뉴는 mainMenu 이다라고 지정을 하는 것이다.
# tearoff 속성은 메뉴의 점선을 없애준다.
fileMenu = Menu(mainMenu, tearoff=False)
# 다른 메뉴가 확장이 되어야 되기 때문에 add_cascade() 사용하여 메뉴의 이름을 '파일'로 설정하였고
# menu 속성값을 fileMenu 로 지정하였다.
mainMenu.add_cascade(label="파일", menu=fileMenu)

# 하위 메뉴를 만들어 보기
fileMenu.add_command(label="열기")
fileMenu.add_separator()    # 구분선
fileMenu.add_command(label="종료")

root.mainloop()