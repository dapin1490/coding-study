mini = 1000001
maxi = 0
t = int(input())
nums = list(map(int, input().split()))
for i in range(t):
    if nums[i] < mini:
        mini = nums[i]
    if nums[i] > maxi:
        maxi = nums[i]

print(mini * maxi)
