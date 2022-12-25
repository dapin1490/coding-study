mush = [0] * 10
mush[0] = int(input())
for i in range(1, 10):
    mush[i] = int(input())
    mush[i] += mush[i - 1]

for i in range(0, 10):
    mush[i] = 100 - mush[i]

ans = mush[0]
for i in range(1, 10):
    if (abs(mush[i]) < abs(ans)) or (abs(mush[i]) == abs(ans) and mush[i] < ans):
        ans = mush[i]

print(100 - ans)
