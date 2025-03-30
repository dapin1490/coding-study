/*
https://school.programmers.co.kr/learn/courses/30/lessons/92341
---
주차장의 요금 정책과 차 번호별 입출차 기록이 주어진다. 요금을 계산하여 차 번호 오름차순으로 반환하라.
*/

// #include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct rcd {
    string start = "00:00";
    string end = "23:59";
    int minute = 0;
    int fee = 0;
    bool is_in = false;
};

int cal_time(rcd record) {
    int start_h = stoi(record.start.substr(0, 2));
    int start_m = stoi(record.start.substr(3, 2));
    int end_h = stoi(record.end.substr(0, 2));
    int end_m = stoi(record.end.substr(3, 2));
    int len = 0;

    if (end_m < start_m) {
        end_h--;
        end_m += 60;
    }
    len += (end_m - start_m);
    len += (end_h - start_h) * 60;

    return len;
}

int cal_fee(vector<int>& fees, rcd record) {
    int fee = fees[1];

    if (record.minute > fees[0]) {
        record.minute -= fees[0];
        fee += (record.minute / fees[2]) * fees[3];
        if (record.minute % fees[2] != 0)
            fee += fees[3];
    }

    return fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, rcd> cars;

    for (string line : records) {
        string time = line.substr(0, 5);
        int car_num = stoi(line.substr(6, 4));
        string flag = line.substr(11, 2);

        if (flag == "IN") {
            if (cars.find(car_num) == cars.end()) {
                cars[car_num] = rcd();
            }
            cars[car_num].start = time;
            cars[car_num].end = "23:59";
            cars[car_num].is_in = true;
        }
        else {
            cars[car_num].end = time;
            cars[car_num].is_in = false;
            cars[car_num].minute += cal_time(cars[car_num]);
        }
    }

    for (auto i = cars.begin(); i != cars.end(); i++) {
        if (i->second.is_in) {
            i->second.minute += cal_time(i->second);
            i->second.is_in = false;
        }
        i->second.fee = cal_fee(fees, i->second);
        answer.push_back(i->second.fee);
    }

    return answer;
}

// void sol_test() {
//     int f, r;
//     vector<int> fees;
//     vector<string> records;
//     vector<int> sol;
//     string temp;

//     cin >> f >> r;

//     for (int i = 0; i < f; i++) {
//         int temp;
//         cin >> temp;
//         fees.push_back(temp);
//     }
//     getline(cin, temp);
//     for (int i = 0; i < r; i++) {
//         getline(cin, temp);
//         records.push_back(temp);
//     }

//     sol = solution(fees, records);

//     for (auto i : sol)
//         cout << i << " ";

//     return;
// }

// int main() {
//     ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//     int t;

//     cin >> t;

//     for (int i = 1; i <= t; i++) {
//         cout << "CASE " << i << "\n";
//         sol_test();
//         cout << "\n\n";
//     }

//     return 0;
// }