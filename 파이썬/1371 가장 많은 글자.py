ar = [0] * 26
maxi = 0
while True: # True는 대문자로 써야 한다
    try:
        # 입력이 있는 동안 실행할 명령
        s = input()
        for c in s:
            if c != ' ':
                idx = ord(c) - ord('a')
                ar[idx] += 1
                if ar[idx] > maxi:
                    maxi = ar[idx]
    
    except EOFError:
        break

for i in range(26):
    if ar[i] >= maxi:
        print(chr(i + ord('a')), end='')
