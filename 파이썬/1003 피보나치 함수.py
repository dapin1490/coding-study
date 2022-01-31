# 피보나치 수열 일반항 사용
# 출처 : https://shoark7.github.io/programming/algorithm/%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%EC%9D%84-%ED%95%B4%EA%B2%B0%ED%95%98%EB%8A%94-5%EA%B0%80%EC%A7%80-%EB%B0%A9%EB%B2%95


def fibo(n):
    sqrt_5 = 5 ** (1/2)
    ans = 1 / sqrt_5 * ( ((1 + sqrt_5) / 2) ** n  - ((1 - sqrt_5) / 2) ** n )
    return int(ans)


t = int(input())
for _ in range(t):
    n = int(input())
    if n == 0:
        print("1 0")
    else:
        print("{} {}".format(int(fibo(n - 1)), int(fibo(n))))
