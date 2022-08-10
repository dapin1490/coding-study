score = [0] * 6
total = 0

for i in range(6):
	score[i] = int(input())

for i in range(4):
	total += score[i]

total = total - min(score[0], score[1], score[2], score[3]) + max(score[4], score[5])

print(total)
