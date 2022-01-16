n = int(input())
layer = 1
total = 1

while n > total:
    layer += 1
    total += layer
layer += 1

div = total - n + 1

if layer % 2 == 1:
    print("{}/{}".format(layer - div, div))
else:
    print("{}/{}".format(div, layer - div))
