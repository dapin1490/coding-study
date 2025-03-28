/*
https://www.acmicpc.net/problem/28702
---
3의 배수에서 “Fizz”, 5의 배수에서 “Buzz”, 둘 다 해당하면 둘 다 출력하는 변형된 369 게임이다.
세 개의 연속된 자연수의 게임 결과를 보여줄 테니 다음 결과를 맞혀라
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string nums[3];
    int key = 0;

    cin >> nums[0] >> nums[1] >> nums[2];

    for (int i = 0; i < 3; i++) {
        if (nums[i] != "Fizz" && nums[i] != "Buzz" && nums[i] != "FizzBuzz") {
            key = stoi(nums[i]) + (3 - i);
            break;
        }
    }

    if (key % 15 == 0)
        cout << "FizzBuzz";
    else if (key % 3 == 0)
        cout << "Fizz";
    else if (key % 5 == 0)
        cout << "Buzz";
    else
        cout << key;

    return 0;
}