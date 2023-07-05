# https://www.acmicpc.net/problem/1254
# https://dapin1490.github.io/satinbower/posts/it-boj-1254/

"""
def min_palindrome(word: str) -> int:
    edited_word = word
    num_char = 0

    while not is_pal(edited_word):
        num_char += 1
        edited_word = fill_pal(word + ('-' * num_char))

    return len(edited_word)

def fill_pal(word: str) -> str:
    word_lis = list(word)
    for i in range(len(word_lis) - 1, -1, -1):
        if word_lis[i] == '-':
            word_lis[i] = word_lis[len(word_lis) - 1 - i]
    return to_string(word_lis)

def to_string(lis: list) -> str:
    word = ''
    for char in lis:
        word += char
    return word

def is_pal(word: str) -> bool:
    for i in range(len(word) // 2):
        if word[i] != word[len(word) - 1 - i]:
            return False
    return True

print(min_palindrome(input()))
"""

def min_palindrome(word: str) -> int:
    while not is_pal(word):
        word += '-'
    return len(word)

def is_pal(word: str) -> bool:
    for i in range(len(word) // 2):
        if word[len(word) - 1 - i] == '-':
            continue
        if word[i] != word[len(word) - 1 - i]:
            return False
    return True

print(min_palindrome(input()))