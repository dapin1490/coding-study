nums = input()
nums_data = nums.split(" ")
A = int(nums_data[0])
B = int(nums_data[1])
if A > B:
    print(">")
elif A < B:
    print("<")
elif A == B:
    print("==")
