import sys

n = int(sys.stdin.readline().strip())
st = {0}

for _ in range(n):
    word = list(sys.stdin.readline().strip())
    word.sort()
    word = str(word)
    st.add(word)

print(len(st) - 1)
