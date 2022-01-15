s = input()
ar = ["dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z="]

for i in ar:
    s = s.replace(i, "#")

print(len(s))
