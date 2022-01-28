# 참고 : 15650 N과 M (2)
# 백트래킹 사용

# 전역변수 선언
global n, m, card, nvi, v, max_sum, idx
n, m = map(int, input().split())  # 입력값
card = list(map(int, input().split()))  # 전체 카드 저장
nvi = [False] * n  # 카드 사용 여부 저장
v = []  # 더해야 할 3장의 카드 저장
max_sum = 0  # 답
idx = 0  # 최근 사용한 카드의 인덱스 저장


# 2798 블랙잭
def jack():
    # 전역변수 선언
    global n, m, card, nvi, v, max_sum, idx
    # 3장을 다 뽑았을 때
    if len(v) == 3:
        temp_sum = 0  # 지금 뽑은 3장의 합 저장
        for k in v:
            temp_sum += k
        if max_sum < temp_sum <= m:  # 정답 조건에 맞으면 답에 저장
            max_sum = temp_sum
        return

    # 카드 3장 뽑기
    for i in range(n):
        if nvi[i] or i < idx:  # 중복 방지, 오름차순
            continue
        v.append(card[i])  # 더해야 할 카드에 추가
        idx = i  # 인덱스 기록
        nvi[i] = True  # 사용 여부 기록
        jack()  # 재귀 호출
        del v[len(v) - 1]  # 사용한 카드 버림
        idx = 0  # 인덱스 초기화
        nvi[i] = False  # 사용 여부 초기화


# 실행
jack()
print(max_sum)
