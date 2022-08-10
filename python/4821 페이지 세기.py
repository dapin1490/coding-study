# backpaper
# 4821 페이지 세기
while True:
    total = int(input())  # 총 페이지 수

    if total == 0:  # 입력이 끝남
        break

    print_page = [False] * (total)  # 인쇄할 페이지 표시
    print_count = 0  # 인쇄할 페이지 수
    pages = list(map(str, input().split(',')))  # 인쇄 목록

    for p in pages:
        multi = p.count('-')  # 범위 인쇄 여부 확인

        if multi > 0:  # 범위 인쇄
            start, end = map(int, p.split('-'))

            if start > end or start > total:  # 시작 페이지가 끝 페이지보다 뒤에 있다면 패스
                continue

            for i in range(start - 1, min(end, total)):  # 인쇄 기록이 최대 페이지를 넘어가지 않게 함
                if print_page[i]:  # 이미 인쇄 목록에 들어간 페이지는 True로 표시되어 패스
                    continue
                else:
                    print_page[i] = True
                    print_count += 1

        else:  # 단일 페이지 인쇄
            idx = int(p) - 1
            if idx >= total:
                continue
            if print_page[idx]:  # 이미 인쇄 목록에 들어간 페이지는 True로 표시되어 패스
                continue
            else:
                print_page[idx] = True
                print_count += 1

    # 인쇄할 페이지 확인 완료
    print(print_count)
