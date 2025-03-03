min_odd = 100
sum_odd = 0

for _ in range(7):
    n = int(input())
    if n % 2 == 1:
        sum_odd += n
        if n < min_odd:
            min_odd = n

if sum_odd == 0:
    print(-1)
else:
    print("{}\n{}".format(sum_odd, min_odd))
