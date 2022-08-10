# 리스트 생성과 동시에 초기화하기
# 리스트에 bool 값도 저장할 수 있다
ran = 123456 * 2 + 1
ar = [True] * ran
ar[0] = False
ar[1] = False

for i in range(2, ran // 2 + 1):
    for j in range(2 * i, ran + 1, i):
        if ar[j]:
            ar[j] = False

while True:
    n1 = int(input())
    if n1 == 0:
        break
    n2 = n1 * 2

    count = 0
    for k in range(n1 + 1, n2 + 1):
        if ar[k]:
            count += 1

    print(count)
