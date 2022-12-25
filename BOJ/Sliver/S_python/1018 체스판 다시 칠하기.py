bod = [""] * 51  # 주어진 체스판 가로줄 하나씩 저장.
# 배열의 크기는 주어진 입력의 최댓값에 맞춘다. 1은 여분이다.
cut_b = [""] * 9  # 미니 체스판을 저장할 배열. 원래 미니 체스판은 8줄이지만 1은 여분이다.
n, m = map(int, input().split())  # 주어진 체스판의 크기
key = ""  # 체스판의 색을 검사할 때 사용
value = ""  # key는 원래 있어야 할 색, value는 미니 체스판에 실제 있는 색
min_count = 33  # 답으로 출력할 mincount
cnt = 0  # 미니 체스판마다 개수를 셀 cnt
# 체스판이 단색이라고 해도 최대 32칸을 칠할 수 있기 때문에 mincount의 초기값은 33으로 정했다.
# 사실 몇으로 하든 충분히 크기만 하다면 상관 없다.

# 입력을 받아서 한 줄씩 string으로 배열에 저장한다
for ii in range(n):
    bod[ii] = input()

# 자를 수 있는 최대 횟수만큼 반복
w = m - 8 + 1  # 가로
h = n - 8 + 1  # 세로
for i in range(0, h * w):
    # print("\ncutted board " + str(i + 1) + "\n")  # 디버깅용 출력문. 이번 미니 체스판이 몇 번째인지 출력한다.
    # 체스판 자르기
    for j in range(i // w, i // w + 8):  # 위에서 몇 번째 줄부터 자를지
        cut_b[j - i // w] = bod[j][i % w: i % w + 8]  # 왼쪽에서 몇 번째 글자부터 자를지
        # print(cut_b[j - i // w])  #디버깅용 출력문. 잘라낸 미니 체스판을 가로로 한 줄씩 출력한다.

    # 미니 체스판에서 칠해야 할 칸의 수를 셈
    # 첫 칸이 검은색일 경우
    cnt = 0
    key = "B"
    for a in range(8):
        for b in range(8):
            value = cut_b[a][b:b + 1]
            # print("start B : (" + str(a + 1) + ", " + str(b + 1) + ") cnt = ")  # 디버깅용 출력문. 이번에 검사하는 칸의 인덱스를 출력한다.
            # 지금 검사하는 칸에 칠해져 있어야 하는 색을 기준으로
            if key == "W":
                if key != value:  # 잘못된 색이 칠해져 있다면
                    cnt += 1
                key = "B"  # 다음 검사를 위한 초기화
                # print(cnt)  # 디버깅용 출력문. 이번 검사로 업데이트한 cnt를 출력한다.
            elif key == "B":
                if key != value:  # 잘못된 색이 칠해져 있다면
                    cnt += 1
                key = "W"  # 다음 검사를 위한 초기화
                # print(cnt)  # 디버깅용 출력문. 이번 검사로 업데이트한 cnt를 출력한다.

        # 줄이 바뀔 때는 색이 바뀌지 않음
        # 직전의 반복에서 다음 검사를 위한 초기화가 되었을 것이므로 다시 초기화한다.
        if key == 'W':
            key = 'B'
        else:
            key = 'W'

        if min_count < cnt:  # cnt가 최솟값이 아니라면 중단
            break

    if min_count > cnt:  # min_count 업데이트
        min_count = cnt

    # 첫 칸이 흰색일 경우
    # key = "W"로 초기화하고 시작한다는 점을 제외하면 첫 칸이 검은색일 경우와 완전히 똑같으므로 주석은 추가하지 않았다.
    cnt = 0
    key = "W"
    for a in range(8):
        for b in range(8):
            value = cut_b[a][b:b + 1]
            # print("start B : (" + str(a + 1) + ", " + str(b + 1) + ") cnt = ")
            if key == "W":
                if key != value:
                    cnt += 1
                key = "B"
                # print(cnt)
            elif key == "B":
                if key != value:
                    cnt += 1
                key = "W"
                # print(cnt)

        # 줄이 바뀔 때는 색이 바뀌지 않음
        if key == 'W':
            key = 'B'
        else:
            key = 'W'

        if min_count < cnt:  # 최솟값이 아니라면 중단
            break

    if min_count > cnt:
        min_count = cnt

print(min_count)  # 답 출력
