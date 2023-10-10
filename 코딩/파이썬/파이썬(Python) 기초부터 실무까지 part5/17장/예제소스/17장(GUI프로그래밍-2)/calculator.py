# 계산기 프로그램 만들기
from tkinter import *

window = Tk()
window.title("계산기")
display = Entry(window, width=33, bg="yellow")
# 사용자로부터 수식을 입력받고 계산 결과를 보여주는 엔트리위젯 열 병합으로 처리
display.grid(row=0, column=0, columnspan=5)
# 버튼에 표식될 텍스트를 리스트로 값을 설정함.
button_list = [
    "7", "8", "9", "/", "C",
    "4", "5", "6", "*", " ",
    "1", "2", "3", "-", " ",
    "0", ".", "=", "+", " "
]

# 함수 정의
def click(key):
    # 매개변수 key 값이 = 이라면 계산을 하라는 의미
    if key == "=":
        # eval() 는 사용자가 "2","+","3"클릭하면 문자열을 생성한다.
        # 2+3으로 숫자로 변환하여 계산하여 준다.
        result = eval(display.get())
        s = str(result)
        # 결과를 표식을 함
        display.insert(END, "=" + s)
    # 매개변수가 값이 "C"라면 엔트리의 값을 다 지워야한다.
    elif key == "C":
        display.delete(0, END)
    else:
        display.insert(END, key)

row_index = 1
col_index = 0
# 버튼을 생성해서 리스트에 있는 값을 표식한다.
# 17개의 버튼에 전부 이벤트 처리를 해야하는데 하나의 함수를 정의해서 람다식으로 호출만
# 하게끔 아래코드에서 작성을 하였다.
# lambda t=button_text : click(t) 코드를 일반코드로 바꾸면 아래와 같다.
# def process(t=button_text)
#     click(t)
for button_text in button_list:
    Button(window, text=button_text,width=5,command=lambda t=button_text:
                   click(t)).grid(row=row_index,column=col_index)
    col_index += 1   # 열의 인덱스를 증가함.
    # 5열까지 배치가 되면 행을 바꾼다.
    if col_index > 4:
        row_index += 1
        col_index = 0

window.mainloop()