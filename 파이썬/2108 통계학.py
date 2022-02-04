import sys  # 입출력 시간 단축

cn = [0] * 8002  # 카운팅 배열
ans = [0, 0, 0, 0]  # 순서대로 평균, 중앙값, 최빈값, 범위
# 산술 평균 : 입력받을 때 전부 더한 다음 수의 개수로 나눔. 더블 주의
# 중앙값 : 최빈값을 구한 후 카운팅 배열을 누적하여 가운데 위치해야 하는 값을 구함
# 최빈값 : 카운팅 배열을 누적하기 전 개수의 최댓값 찾기
# 범위 : maxi - mini
bin_cnt = 0  # 최빈값의 카운트 수
maxi = -4010  # 범위를 찾기 위한 최댓값
mini = 4010  # 범위를 찾기 위한 최솟값

t = int(sys.stdin.readline().rstrip())  # 수의 개수, 입출력 시간 단축
a = 0  # 입력받기용 아무데나 쓸 변수
for _ in range(t):
    a = int(sys.stdin.readline().rstrip())  # 입출력 시간 단축
    cn[a + 4000] += 1  # 개수 세기
    ans[0] += a  # 총합 구하기
    if a > maxi:  # 최댓값
        maxi = a
    if a < mini:  # 최솟값
        mini = a
    if cn[a + 4000] > bin_cnt:  # 일단 최빈값 하나 구하기
        ans[2] = a
        bin_cnt = cn[a + 4000]

# 평균과 범위
ans[3] = maxi - mini
a = ans[0]
ans[0] = round(a / t)

# 최빈값이 여러 개 있는지 확인
multi = False
for i in range(8001):
    if cn[i] == bin_cnt and i - 4000 != ans[2]:
        multi = True
        break
if multi:
    multi = False
    for j in range(8001):
        if cn[j] == bin_cnt and not multi:
            multi = True
        elif cn[j] == bin_cnt and multi:
            ans[2] = j - 4000
            break

# 카운팅 누적하기
cnt = 0
a = 0
while True:
    if cnt >= int((t + 1) / 2):
        ans[1] = a - 1 - 4000
        break
    cnt += cn[a]
    a += 1

# 출력
for answer in ans:
    print(answer)
