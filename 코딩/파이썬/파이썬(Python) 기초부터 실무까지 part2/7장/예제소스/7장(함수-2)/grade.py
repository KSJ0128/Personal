# grade 모듈 만들기

# 아래 함수는 사용자로부터 성적을 입력받는다.사용자가 음수를 입력을 하면
# 성적을 입력받는 것을 멈추도록 한다.
def readList():
    score_list = []     # 성적을 저장할 리스트 타입의 변수선언
    flag = True         # 무한루프를 빠져나가기 위한 불타입의 변수

    # 무한 루프를 돌도록 한다.
    while flag:
        score = int(input("성적을 입력하세요(종료를 하시려면 음수를 입력) : "))
        # 음수가 들어왔는지 체크를 하는 부분(무한루프 탈출 구간)
        if score < 0:
            flag = False
        else:
            score_list.append(score)     # 점수를 리스트에 추가하는 코드

    return score_list

# 입력받은 성적의 오름차순 정렬하는 함수
def sortingList(score_list):
    score_list.sort()
    return score_list

# 오름차순 정렬이 된 성적을 출력하는 함수
def show_score(score_list):
    j = 0
    for i in score_list:
        print((j+1),"번째 성적 : ", i)
        j += 1
            