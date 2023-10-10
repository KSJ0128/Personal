# 메모장 만들기
# 1단계 : GUI 만들기
# 2단계 : 파일 메뉴 기능 입히기
# 3단계 : 편집 메뉴 기능 입히기
# 4단계 : 도움말 메뉴 기능 입히기

from tkinter.filedialog import *
# 파일 이름을 가져오기 위해서 os 모듈을 임포트
import os
# 전역변수 초기화
es = ""

# 새파일 메뉴 클릭시 호출되는 함수를 정의
def newFile():
    top.title("제목없음-메모장")
    # 새파일은 Text 위젯안에 내용을 다 지우면 되는 것이다. text 의 인덱스는 y.x 다시말해서
    # x열을 사용한다. 1.0은 첫 번째줄, 첫 번째 문자가 된다.
    ta.delete(1.0, END)

# 열기 메뉴 클릭시 호출되는 함수를 정의
def openFile():
    file = askopenfilename(title="파일 열기",
                           filetypes=(("텍스트파일","*.txt"),("모든파일","*.*")))
    # 열려진 파일의 이름으로 타이틀 설정
    top.title(os.path.basename(file) + "-메모장")
    ta.delete(1.0, END)
    f = open(file, "r")
    # read()는 파일내용을 전부 문자열로 리턴해준다.
    # 문자셋을 서로 일치를 시켜줘야 한다.메모장으로 ANSI 로 저장을 하면 문제가 없다.
    ta.insert(1.0, f.read())
    f.close()

# 파일 저장 메뉴 클릭시 호출되는 함수 정의
def saveFile():
    f = asksaveasfile(mode="w", defaultextension=".txt")
    if f is None:    # 파일 없으면 무효화 처리를 해주도록 한다.
        return
    # 저장하기 위해서 텍스트 위젯의 내용을 처음부터 끝까지 가져오는 코드
    ts = str(ta.get(1.0, END))
    f.write(ts)   # 파일 저장
    f.close()

# 종료 메뉴를 클릭시 호출되는 함수 정의
def memo_exit():
    top.quit()
    top.destroy()

# 편집 메뉴 기능 입히기
# 잘라내기 메뉴를 클릭시 호출되는 함수 정의
def cut():
    global es
    # es 변수에게는 선택된 문자열을 저장한 후 삭제를 해야 한다.
    # 문자열의 인덱스는 시작이 SEL_FIRST, 마지막이 SEL_LAST로 접근 가능하다.
    # 선택된 문자열 부분은 색상을 주도록 한다.
    es = ta.get(SEL_FIRST, SEL_LAST)
    ta.delete(SEL_FIRST, SEL_LAST)    # 잘라내기 한 부분은 지운다.

# 복사하기 메뉴를 클릭시 호출되는 함수 정의
def copy():
    global es
    es = ta.get(SEL_FIRST, SEL_LAST)

# 붙이기 메뉴를 클릭시 호출되는 함수 정의
def paste():
    global es
    # INSERT 상수는 커서의 위치를 가지고 있다.
    ta.insert(INSERT, es)

# 삭제하기 메뉴를 클릭시 호출되는 함수 정의
def delete():
    ta.delete(SEL_FIRST, SEL_LAST)

# 도움말 메뉴를 클릭시 호출되는 함수 정의
def help():
    he = Toplevel(top)
    he.geometry("200x200")
    he.title("정보")
    lbl = Label(he, text="메모장 버전 1.0\n 파이썬으로 만든 메모장!")
    lbl.pack()


if __name__ == "__main__":
    top = Tk()
    top.title("메모장")
    top.geometry("400x400")

    ta = Text(top)   # 텍스트 위젯을 생성함
    sb = Scrollbar(ta)   # 텍스트 위젯의 스크롤바를 생성함
    sb.config(command=ta.yview())
    sb.pack(side=RIGHT, fill=Y)

    # 메모장의 기본크기를 400,400으로 설정을 했지만 필요하다면 크기를 확대를 시킬수도
    # 있다.이때 Text 위젯이 자동으로 확대가 되기 위해서 아래와 같은 코드를 작성함.
    # weight 는 상대적인 크기를 나타내는 매개변수이며 1로 지정을 하면 전체화면의
    # 크기에 맞추어서 확장이 자동으로 이루어진다.
    top.grid_rowconfigure(0, weight=1)   # 줄을 전체 크기로 설정함
    top.grid_columnconfigure(0, weight=1)   # 열을 전체 크기로 설정함
    ta.grid(sticky=N+E+S+W)    # Text 위젯이 좌우 상하를 다 채우도록 고정

    # 메뉴 만들기
    mb = Menu(top)
    # 파일 메뉴를 만드는 코드
    fi = Menu(mb, tearoff=False)   # 점선 없애기
    fi.add_command(label="새파일", command=newFile)
    fi.add_command(label="열기", command=openFile)
    fi.add_command(label="저장", command=saveFile)
    fi.add_separator()     # 분리선 추가
    fi.add_command(label="종료", command=memo_exit)
    mb.add_cascade(label="파일", menu=fi)  # 파일 메뉴를 메뉴바에 붙이기

    # 편집 메뉴를 만드는 코드
    e = Menu(mb, tearoff=False)
    e.add_command(label="잘라내기", command=cut)
    e.add_command(label="복사", command=copy)
    e.add_command(label="붙이기", command=paste)
    e.add_command(label="삭제", command=delete)
    mb.add_cascade(label="편집", menu=e)   # 편집 메뉴를 메뉴바에 붙이기

    # 도움말 메뉴를 만드는 코드
    h = Menu(mb, tearoff=False)
    h.add_command(label="메모장 정보", command=help)
    mb.add_cascade(label="도움말", menu=h)   # 도움말 메뉴를 메뉴바에 붙이기

    top.config(menu=mb)
    top.mainloop()