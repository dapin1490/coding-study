l, p = map(int, input().split())
news = list(map(int, input().split()))
p *= l

for n in news:
    print(n - p, end=' ')
