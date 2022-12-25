nvi = [0, 0, 0, 0, 0, 0, 0, 0]
v = []
global pre_num
pre_num = 0


def pr(n, m):  # n개의 수 중에서 중복 없이 오름차순으로 m개의 수를 뽑음
    global pre_num
    if len(v) == m:  # 필요한 만큼 수를 뽑았을 때 실행
        # 뽑은 수를 출력한다.
        for k in v:
            print(k, end=" ")
        print()
        return  # 실행이 끝나고 이전 호출로 되돌아간다.

    # 아직 수를 충분히 뽑지 못했을 때
    for i in range(n):  # 숫자의 총 개수만큼 반복 : 첫 번째 숫자부터 끝까지 하나씩 조건에 맞는지 시도해본다
        if nvi[i] or (i + 1) < pre_num:  # 이미 뽑은 숫자이거나 직전에 뽑은 숫자보다 작은 숫자일 경우
            continue  # 숫자를 뽑지 않고 넘긴다
        v.append(i + 1)  # 넘기지 않았다면 숫자를 뽑는다.
        pre_num = i + 1  # 오름차순으로 하기 위해 지금 뽑은 숫자를 기록한다.
        nvi[i] = 1  # 중복 방지를 위해 뽑았다는 것도 표시해 둔다.
        pr(n, m)  # 재귀 호출
        idx = len(v)
        del v[idx - 1]  # 호출에서 되돌아왔을 때 실행한다. 뽑은 숫자를 하나 버린다.
        pre_num = 0  # 기록한 숫자를 지운다.
        nvi[i] = 0  # 뽑았다는 표시도 지운다.


if __name__ == '__main__':
    nn, mm = map(int, input().split())
    pr(nn, mm)
