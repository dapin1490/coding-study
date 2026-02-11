import statistics

n = int(input())
scores = list(map(int, input().split()))
max_score = 0

for i in range(n):
    if scores[i] > max_score:
        max_score = scores[i]

for i in range(n):
    scores[i] = scores[i] / max_score * 100

print(statistics.mean(scores))
