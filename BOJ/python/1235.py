import sys

input = sys.stdin.readline
print = sys.stdout.write

def boj1235() -> None:
    n = int(input())
    nums = [""] * n
    ok = False
    answer = len(str(n)) - 1

    for i in range(n):
        nums[i] = input().strip()[::-1]
    nums.sort()

    while not ok:
        ok = True
        answer += 1
        for i in range(1, len(nums)):
            if nums[i - 1][:answer] == nums[i][:answer]:
                ok = False
                break

    print(f'{answer}')

    return

boj1235()
