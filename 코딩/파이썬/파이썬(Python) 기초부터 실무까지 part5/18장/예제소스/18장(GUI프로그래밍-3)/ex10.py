# 파일 열기, 저장 실습

# 파일 열기 filedialog 를 임포트를 해야한다.
from tkinter import *
from tkinter.filedialog import *

root = Tk()
root.title("파일 열기")
root.geometry("400x100")

lbl1 = Label(root, text="선택된 파일 이름")
lbl1.pack()
# askopenfilename() 함수는 filetypes 에 들어가는 값이 튜플형태로 들어간다.
# 경로를 포함해서 선택한 파일명을 반환한다.
filename = askopenfilename(parent=root, filetypes=(("gif파일","*.gif"),("png파일","*.png"),("모든파일","*.*")))
# 선택되어진 파일이름이 레이블에 표식이 된다.
lbl1.configure(text=str(filename))
root.mainloop()

