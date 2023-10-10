# 레이블의 텍스트 값을 가져오는 방법 실습하기
# 1번째 방법 : cget() 이용

import tkinter as tk

# class Test():
#     def __init__(self):
#         self.root = tk.Tk()    # 루트 윈도우를 생성
#         self.root.geometry("200x80")  # 윈도우의 크기를 설정
#         self.label = tk.Label(self.root, text="레이블 예제")
#         # 버튼을 클릭하면 readLabelText() 메서드가 호출됨
#         self.button = tk.Button(self.root, text="레이블의 텍스트 값 읽기",
#                                 command=self.readLabelText)
#         self.button.pack()
#         self.label.pack()
#         self.root.mainloop()
#     # 레이블에 있는 text 속성의 값을 출력을 하는 메서드
#     def readLabelText(self):
#         print(self.label.cget("text"))

# 2번째 방법 : 레이블 객체도 "text"키에 접근해서 레이블 텍스트 얻기
# class Test():
#     def __init__(self):
#         self.root = tk.Tk()    # 루트 윈도우를 생성
#         self.root.geometry("200x80")  # 윈도우의 크기를 설정
#         self.label = tk.Label(self.root, text="레이블 예제")
#         # 버튼을 클릭하면 readLabelText() 메서드가 호출됨
#         self.button = tk.Button(self.root, text="레이블의 텍스트 값 읽기",
#                                 command=self.readLabelText)
#         self.button.pack()
#         self.label.pack()
#         self.root.mainloop()
#     # 레이블에 있는 text 키의 값을 출력을 하는 메서드
#     def readLabelText(self):
#         print(self.label["text"])


# 3번째 방법 : Stringvar 클래스를 이용하여 레이블의 텍스트를 얻는 방법
# Stringvar 클래스는 Tkinter 문자열 변수를 만드는 Tkinter 생성자의 한 유형
class Test():
    def __init__(self):
        self.root = tk.Tk()    # 루트 윈도우를 생성
        self.root.geometry("200x80")  # 윈도우의 크기를 설정
        self.text = tk.StringVar()  # StringVar() 인스턴스 생성
        self.text.set("레이블 예제")  # StringVar() 에 문자열 지정
        # StringVar() 의 text 값을 레이블의 텍스트를 대입
        self.label = tk.Label(self.root, textvariable=self.text)
        # 버튼을 클릭하면 readLabelText() 메서드가 호출됨
        self.button = tk.Button(self.root, text="레이블의 텍스트 값 읽기",
                                command=self.readLabelText)
        self.button.pack()
        self.label.pack()
        self.root.mainloop()
    # StringVar 인스턴스의 get()를 통하여 레이블의 텍스를 출력
    def readLabelText(self):
        print(self.text.get())

if __name__ == "__main__":
    app = Test()
        
        