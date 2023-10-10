# 문제
# 머리 글자어(acronym)은 NATO(North Atlantic Treaty Organization)처럼
# 각 단어의 첫 글자를 모아서 만든 문자열이다. 사용자로부터 문장을 입력하면 해당
# 되는 머리 글자어를 출력하는 프로그램을 만들어보자.
# 출력결과
# 문자열을 입력하시오 : North Atlantic Treaty Organization
# 머리문자열 : NATO
#------------------------------------------------------------------
def main():
    string = input("문자열을 입력하시오 : ")
    acronym = ""
    # 입력받은 문자열을 일단 대문자로 바꾼 후, 문자열을 분리
    for word in string.upper().split():
        acronym += word[0]

    print("머리문자열 : " + acronym)

if __name__ == "__main__":
    main()