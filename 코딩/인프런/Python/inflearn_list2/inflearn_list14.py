# 성적 처리 프로그램 만들기(2차원 리스트)
# 주어진 성적
# score = [[100, 100, 100], [20, 20, 20], [30, 30, 30], 
# [40, 40, 40],[50,50,50]]
# 출력 결과
# 번호    국어    영어      수학    총점    평균
# ------------------------------------------------------
# 1     100     100     100     300     100.00
# 1     20     20     20     20     20.00
# 1     30     30     30     30     30.00
# 1     40     100     100     300     100.00
# 1     100     100     100     300     100.00
# ------------------------------------------------------
# 총점      240     240     240     720     48.00

score = [[100, 100, 100], [20, 20, 20], [30, 30, 30],[40, 40, 40],[50,50,50]]
korTotal = 0
engTotal = 0 
mathTotal = 0
totalSum = 0
avg = 0.0

print("번호    국어    영어    수학    총점    평균")
print("------------------------------------------------------")

for i in range(len(score)):
    sum = 0 # 개인 총점
    average = 0.0 # 개인 평균

    korTotal += score[i][0]
    engTotal += score[i][1]
    mathTotal += score[i][2]
    
    # 번호 출력
    print("%3d" % (i+1), end = "\t")

    for j in range(len(score[i])):     
        sum += score[i][j]
        print("\t%d" % score[i][j], end = "\t")

        totalSum += sum
        average = sum / len(score[i])
        avg += average
        print("\t%d\t\t%2.f" % (sum, average))
avg /= len(score)
print("------------------------------------------------------")
print("총점 \t%d\t%d\t%d\t%d\t%.2f" % (korTotal, engTotal, mathTotal, totalSum, avg))