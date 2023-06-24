# https://www.acmicpc.net/problem/1213
# https://dapin1490.github.io/satinbower/posts/it-boj-1213/

# 1
def make_palindrome(word: str) -> str:
    alphabets = [0] * 26
    int_a = ord('A')
    ans = ""
    middle_char = None

    for char in word:  # 글자 세기
        alphabets[ord(char) - int_a] += 1

    for i in range(26):  # 팰린드롬 만들기 전 글자 구성 확인
        if alphabets[i] % 2 != 0:  # 홀수 개 있는 글자
            if middle_char is None:  # 처음 나왔으면 가운데 글자로 저장 후 짝수 개 취급
                middle_char = chr(int_a + i)
                ans = middle_char  # 가운데 글자 먼저 놓기
                alphabets[i] -= 1
            else:  # 또 나왔으면 팰린드롬 불가
                return "I'm Sorry Hansoo"
        alphabets[i] //= 2  # 결격사유가 없다면 짝수일 것

    for i in range(25, -1, -1):  # 양 옆에 짝수 글자 놓기
        if alphabets[i] == 0:
            continue
        ans = (chr(int_a + i) * alphabets[i]) + ans + (chr(int_a + i) * alphabets[i])
    return ans

print(make_palindrome(input()))


# 2
def make_palindrome(word: str) -> str:
    alphabets = [0] * 26
    int_a = ord('A')
    ans = ""
    middle_char = None

    for char in word:  # 글자 세기
        alphabets[ord(char) - int_a] += 1

    for i in range(25, -1, -1):
        if alphabets[i] == 0:
            continue
        if alphabets[i] % 2 != 0:  # 홀수 개 있는 글자
            if middle_char is None:  # 처음 나왔으면 가운데 글자로 저장 후 짝수 개 취급
                middle_char = chr(int_a + i)
                alphabets[i] -= 1
            else:  # 또 나왔으면 팰린드롬 불가
                return "I'm Sorry Hansoo"
        alphabets[i] //= 2  # 결격사유가 없다면 짝수일 것
        ans = (chr(int_a + i) * alphabets[i]) + ans + (chr(int_a + i) * alphabets[i])

    if middle_char is not None:
        ans = ans[:len(ans) // 2] + middle_char + ans[len(ans) // 2:]
    return ans

print(make_palindrome(input()))


# 3
def make_palindrome(word: str) -> str:
    alpha = {}
    ans = ""
    middle_char = None

    for char in word:  # 글자 세기
        if char in alpha:
            alpha[char] += 1
        else:
            alpha[char] = 1

    for char in sorted(alpha.keys(), reverse=True):
        if alpha[char] % 2 != 0:  # 홀수 개 있는 글자
            if middle_char is None:  # 처음 나왔으면 가운데 글자로 저장 후 짝수 개 취급
                middle_char = char
                alpha[char] -= 1
            else:  # 또 나왔으면 팰린드롬 불가
                return "I'm Sorry Hansoo"
        alpha[char] //= 2
        ans = (char * alpha[char]) + ans + (char * alpha[char])

    if middle_char is not None:
        ans = ans[:len(ans) // 2] + middle_char + ans[len(ans) // 2:]
    return ans

print(make_palindrome(input()))