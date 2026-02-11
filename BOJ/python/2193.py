n = int(input())
a, b = 1, 1  # a는 N-1단계, b는 N단계 값

for _ in range(3, n + 1):
    a, b = b, a + b  # 동시에 값이 갱신됨 (임시 변수 불필요)

print(b)