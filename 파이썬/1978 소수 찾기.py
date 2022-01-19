def sosu(n):
    if n < 2:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


count = 0
t = int(input())
nums = list(map(int, input().split()))

for num in nums:
    if sosu(num):
        count += 1

print(count)
