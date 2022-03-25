def vowel(c):
  if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
    return True
  else:
    return False


def dokkaebi(n):
  key = n
  while True:
    if vowel(n[0]):
      break

    n = n[1:] + n[0]
    if n == key:
      break

  n += "ay"
  return n


while True:
  s = input()

  if s == "#":
    break

  print(dokkaebi(s))
