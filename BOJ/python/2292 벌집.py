n = int(input())
layer = 1
total = 1

while n > total:
    total += layer * 6
    layer += 1

print(layer)
