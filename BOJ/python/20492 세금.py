n = int(input())

no_cost = int((1 - 0.22) * n)
yes_cost = int(0.8 * n + (1 - 0.22) * 0.2 * n)

print("%d %d" % (no_cost, yes_cost))
