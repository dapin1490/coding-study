def realmsg(s):
    ar = [0] * 26
    key = 'a'
    check = False

    for i in s:
        idx = ord(i) - ord('A')
        ar[idx] += 1

        if ar[idx] == 3 and not check:
            key = i
            check = True
            continue

        if check:
            if key != i:
                return False
            ar[ord(key) - ord('A')] = 0
            check = False

    if check:
        return False
    else:
        return True


t = int(input())
for _ in range(t):
    text = input()

    if realmsg(text):
        print("OK")
    else:
        print("FAKE")
