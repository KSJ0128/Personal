# 이벤트 처리를 활용하여 페이트 프로그램을 구현하기
from tkinter import *
from tkinter.colorchooser import askcolor
# 상수 선언
DEFAULT_PEN_SIZE = 1.0    # 펜 사이즈
DEFAULT_COLOR = "BLACK"   # 색상

# 필요한 변수들을 초기화
mode = "pen"
old_x = None
old_y = None
myColor = DEFAULT_COLOR
erase_on = False

# 이벤트 처리 함수들을 정의
# 펜을 사용하고자 할 때 모드를 "pen"으로 바꾸는 함수
def use_pen():
    global mode
    mode = "pen"
    print("변경모드 : ", mode)
# 색상 버튼이 선택되면 사용자한테 색상을 선택하는 대화상자를 띄운다.
def choose_color():
    global myColor
    # askcolor()의 리턴타입은 튜플인데 인덱스 [1]이 16진수로 색상을 표식
    myColor = askcolor(color=myColor)[1]
    print("변경된 색상 : ", myColor)

# 지우개 버튼이 선택되면 모드를 "erase"으로 바꾼다.
def use_erase():
    global mode
    mode = "erase"
    print("변경모드 : ", mode)

# 그림을 그리는 paint()를 정의한다.
def paint(event):
    global var, erase_on, mode, old_x, old_y
    # 모드가 지우개이면 fill_color 를 white 로 설정하고 아니라면 myColor 로 설정함
    fill_color = "white" if mode == "erase" else myColor
    # old_x와 old_y가 값이 있다면...움직였다라는 것이다.
    if old_x and old_y:
        canvas.create_line(old_x, old_y, event.x, event.y, capstyle=ROUND,
                           width=var.get(),fill=fill_color)
    old_x = event.x
    old_y = event.y

# 사용자가 마우스 버튼에서 손을 떼면 이전 점을 삭제한다.
def reset(event):
    global old_x, old_y
    old_x = None
    old_y = None

# 캔버스에 그려진 모든 그림을 삭제하는 함수
def clear_all():
    global canvas
    canvas.delete(ALL)

#------------------------------------------
# 위젯들 배치
root = Tk()
var = DoubleVar()   # 사이즈 값과 연결되어질 객체를 생성

# 펜이라는 버튼을 만들고 이벤트 처리함수를 use_pen 으로 연결하였다.
penButton = Button(root, text='펜', command=use_pen)
penButton.grid(row=0, column=0, sticky=W+E)

# 색상 선택이라는 버튼을 만들고 이벤트 처리함수를 choose_color 으로 연결하였다.
colorButton = Button(root, text='색상선택', command=choose_color)
colorButton.grid(row=0, column=1, sticky=W+E)

# 지우개라는 버튼을 만들고 이벤트 처리함수를 use_erase 으로 연결하였다.
eraseButton = Button(root, text='지우개', command=use_erase)
eraseButton.grid(row=0, column=2, sticky=W+E)

# 모두삭제라는 버튼을 만들고 이벤트 처리함수를 clear_all 으로 연결하였다.
clearButton = Button(root, text='모두삭제', command=clear_all)
clearButton.grid(row=0, column=3, sticky=W+E)

# Scale 클래스는 값을 설정하기 위한 수치 조정바를 생성하는 클래스
# variable 속성은 수치 조정바의 상태를 저장할 제어 변수
# orient 속성은 수치 조정바의 표시 방향(horizontal, vertical)
scale = Scale(root, variable=var, orient=VERTICAL)
scale.grid(row=1, column=4, sticky=N+S)

canvas = Canvas(root, bg="white", width=600, height=500)
canvas.grid(row=1, columnspan=4)

# 캔버스에 바인딩 처리
canvas.bind("<B1-Motion>", paint)
canvas.bind("<ButtonRelease-1>", reset)


root.mainloop()
