#include <iostream>
#include <vector>
#include <map>
using namespace std;

void boj1015();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    boj1015();

    return 0;
}

void boj1015() {
    int n, nsum = 0;
    vector<int> nums;
    map<int, int> cnts;
    map<int, int>::iterator iter;

    cin >> n;
    nums.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (cnts.find(nums[i]) != cnts.end())
            cnts[nums[i]]++;
        else
            cnts[nums[i]] = 1;
    }

    nsum = cnts.begin()->second;
    cnts.begin()->second = 0;
    for (iter = ++cnts.begin(); iter != cnts.end(); iter++) {
        nsum += iter->second;
        iter->second = nsum - iter->second;
    }

    for (int i = 0; i < n; i++) {
        cout << cnts[nums[i]]++ << " ";
    }

    return;
}