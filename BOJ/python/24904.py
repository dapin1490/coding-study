"""
https://www.acmicpc.net/problem/24904
---
백준 워들
하루 6번 제출 제한
"""

import requests
import random

data_list = []

url = "https://upload.acmicpc.net/b1232df1-45d0-48e5-9129-82f0f16a9e95/"
response = requests.get(url)

if response.status_code == 200:
    text_data = response.text
    data_list = text_data.splitlines()

# if data_list:
#     random_item = random.choice(data_list)
#     print(random_item)

excluded_chars = {'D', 'O', 'N', 'B', 'U', 'E', 'L', 'Y', 'T', 'Z'}

answers = [
    item for item in data_list
    if  item[2] == 'I' and
        item[1] == 'M' and
        item[0] == 'S' and
        not any(char in item for char in excluded_chars)
]

print(random.choice(answers))
print(f'{round(len(answers) / len(data_list) * 100, 4)} %')