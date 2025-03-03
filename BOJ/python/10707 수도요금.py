def x():
    global p, a
    return p * a

def y():
    global b, c, d, p
    if p <= c:
        return b
    else:
        return b + (p - c) * d

a = int(input())
b = int(input())
c = int(input())
d = int(input())
p = int(input())

x = x()
y = y()

print(x if x <= y else y)
