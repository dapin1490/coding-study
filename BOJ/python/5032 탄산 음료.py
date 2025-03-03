a, b, c = map(int, input().split())
bin_bottle = a + b
buy_bottle = 0

while True:
    if bin_bottle < c:
        break

    temp_bottle = bin_bottle // c
    buy_bottle += temp_bottle
    bin_bottle -= (c - 1) * temp_bottle

print(buy_bottle)
