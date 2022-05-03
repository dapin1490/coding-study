birth = list(map(int, input().split()))
today = list(map(int, input().split()))
man = today[0] - birth[0] + (-1 if birth[1] > today[1] or (birth[1] == today[1] and birth[2] > today[2]) else 0)
se = today[0] - birth[0] + 1
youn = today[0] - birth[0]
print(man, se, youn, sep="\n")
