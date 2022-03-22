# 다른 정답 : print("FA")

def f(x):
  return str(int(x[0]) * len(x))


n = input()
key = n
flag = False

while True:
  n = f(str(n))
  if key == n:
    flag = True
    break
  elif len(key) < len(n):
    break;
  else:
    key = n

if flag:
  print("FA")
else:
  print("NFA")
