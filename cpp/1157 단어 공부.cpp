#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {

    // 알파벳의 수를 세기 위해 26칸 배열 생성
    // 한 글자씩 스캔
    // 맞는 자리 찾아서 개수 배열 증가
    // 검사 후 배열에서 가장 큰 값 찾기
    // 최대값이 여러개일 경우의 if 필요함

    int abc[26]; // 알파벳 개수 저장
    for (int i = 0; i < 26; i++)
        abc[i] = 0; // 개수 초기화

    string text; // 입력받을 텍스트
    cin >> text;

    string s;
    for (int i = 0; i < text.length(); i++)
        s += toupper(text.at(i));

    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        int index = static_cast<int>(s.at(i) - 'A');
        abc[index]++;
    }

    int max = 0; // 가장 많이 나온 글자 수
    int maxIndex = 0; // 가장 많이 나온 글자
    char maxChar = 'a';
    bool same = false; // 최대값 중복
    for (int i = 0; i < 26; i++)
    {
        if (abc[i] > max)
        {
            max = abc[i];
            maxIndex = i;
        }
    }

    for (int i = maxIndex + 1; i < 26; i++)
    {
        if (abc[i] == max)
            same = true;
    }


    if (same)
        cout << "?" << endl;
    else
    {
        maxChar = maxIndex + 'A';
        cout << maxChar << endl;
    }


    return 0;
}
