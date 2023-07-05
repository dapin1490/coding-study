# https://www.acmicpc.net/problem/4344

"""
학생의 수와 각 점수 제공, 평균보다 높은 학생의 비율 소수 셋째 자리까지 출력
"""

def cnt_mean():
    k, *line = map(int, input().split())
    k_mean = sum(line) / k
    cnt = 0
    for stud in line:
        if stud > k_mean:
            cnt += 1
    print(f'{cnt / k * 100 :.3f}%')
    return

n = int(input())

for _ in range(n):
    cnt_mean()