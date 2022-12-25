def six(snum):
    ans = 0
    for i in snum:
        num = ord(i)
        if num >= ord('A'):
            ans = (ans + num - ord('A') + 10) * 16
        else:
            ans = (ans + num - ord('0')) * 16
    return ans // 16


n = input()
print(six(n))
