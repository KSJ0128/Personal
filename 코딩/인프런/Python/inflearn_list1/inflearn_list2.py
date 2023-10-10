# 학생 성적 처리 프로그램
# 유저로부터 성적 입력 받고 리스트에 저장
# 성적 평균 구하고 해당 점수가 80점 이상인 학생의 수 출력
# 출력 결과
# 성적을 입력 받기
# 성적: 10, 20, 60, 70, 80
# 성적 평균 출력
# 80점 이상의 성적을 받은 학생 수 출력
# 학생 수는 상수로 STUDENT = 5 사용

STUDENT = 5 # 전역 상수 선언
scores = [] # 학생 성적 저장할 리스트
scores_Sum = 0 # 학생들의 성적 합계 저장
cnt_80 = 0 # 80점 넘는 학생 수 카운트

for i in range(STUDENT):
    score= int(input("성적을 입력하시오: "))
    scores.append(score)  # 학생들의 성적 list에 저장
    scores_Sum += score  # 학생들의 성적 합계
    if(score >= 80):
        cnt_80 += 1

print("성적 평균은", scores_Sum/STUDENT, "입니다.")
print("80점 이상의 성적을 받은 학생은 ", cnt_80, "명입니다.")