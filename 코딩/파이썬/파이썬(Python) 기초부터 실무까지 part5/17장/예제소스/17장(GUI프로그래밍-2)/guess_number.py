# 숫자 추측 게임 만들기
from tkinter import *
import random

answer = random.randint(1, 100)
print("난수 발생 : ", answer)
def guessing():
    # 사용자가 입력한 값을 엔트리에서 가져오고 있다.
    guess = int(guessField.get())
    if guess > answer:
        msg = "높음!"
    elif guess < answer:
        msg = "낮음!"
    else:
        msg = "정답!"
    # 텍스트를 라벨의 값으로 설정함
    resultLabel["text"] = msg
    # 엔트리에 입력되어 있는 값을 지움
    guessField.delete(0, 5)

def reset():
    global answer
    answer = random.randint(1, 100)
    resultLabel["text"] = "다시 한번 도전하세요!"

# ------------------------------------------------------
window = Tk()
window.configure(bg="white")    # 루트윈도우의 배경색을 설정함.
window.title("숫자 추측 게임")    # 윈도우 타이틀 설정
window.geometry("500x100")
titleLabel = Label(window, text="숫자 게임에 오신 것을 환영합니다.!")
titleLabel.pack()

# 추측값을 입력하는 창을 엔트리로 만듬
guessField = Entry(window)
guessField.pack(side=LEFT, padx=15)
# 버튼을 만들고 이벤트 처리 등록
tryButton = Button(window, text="시도", fg="green", bg="white", command=guessing)
resetButton = Button(window, text="초기화", fg="red", bg="white", command=reset)
tryButton.pack(side=LEFT, padx=5)
resetButton.pack(side=LEFT)

resultLabel = Label(window, text="1부터 100사이의 숫자를 입력하세요.", bg="white")
resultLabel.pack(side=LEFT, padx=15)

window.mainloop()