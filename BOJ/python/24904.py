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

# 2025.03.31
# 11000 | 20010 | 22100 | 22020 | 22020 | 22222
# AMOWT | MUDAR | MAIKS | MAZIC | MAVIE | MAFIA

excluded_chars = {'O', 'W', 'T', 'U', 'D', 'R', 'K', 'S', 'Z', 'C', 'V', 'E'}

answers = [
    item for item in data_list
    if  item[3] == 'I' and
        # 'I' in [item[3], item[4]] and
        # 'M' in [item[0], item[2], item[3], item[4]] and
        # item[3] == 'I' and
        item[1] == 'A' and
        item[0] == 'M' and
        not any(char in item for char in excluded_chars)
]

print(random.choice(answers))
print(f'{len(answers)}, {round(len(answers) / len(data_list) * 100, 4)} %')