// 그룹 단어는 단어에 존재하는 모든 문자에 대해서 각 문자가 연속해서 나타나는 단어를 의미한다.
// 예를 들어, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, I, n이 모두 연속해서 나타나기 때문에 그룹단어이다.
// 그러나, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.
// 이때, 알파벳은 소문자와 대문자로 되어 있고 소문자와 대문자는 동일한 알파벳으로 취급한다.
// 단어 N개를 입력으로 받아서 그룹 단어가 아닌 단어의 개수를 출력하는 프로그램을 작성하세요.

// 조건
// 첫번째 줄에 단어의 개수 n이 주어진다. (1<= n<=100)
// 둘째 줄부터 n개의 단어가 제시된다. 단어는 알파벳으로만 되어 있고 중복되지 않으며 길이는 최대 100이다.

// 출력
// 첫번째 줄에 그룹 단어가 아닌 개수를 출력한다.

#include <iostream>
#include <cstring>
using namespace std;

bool findGW(char word[]);
// 아스키코드
// 영대문자 : 65 ~ 90
// 영소문자 : 97 ~ 122
int main() {

  int n; // 단어 개수
  cin >> n;
  int cnt = 0; // 그룹 문자 개수 저장
  
  for (int i = 0; i <= n; i++)
  // 어째선지 i = 0일 때 입력을 받지 않는다. 이유는 모르겠다.
  // 대신 i의 범위에 등호를 넣어 입력을 한 번 더 받게 했다.
  // 만약 입력을 단어 갯수보다 많이 받더라도, 입력값이 없는 findGW 함수는
  // 참을 반환하기 때문에 카운트가 증가하지 않는다
  {
    char words[100];
    cin.getline(words, 101);

    if (!findGW(words))
      cnt++;
  }

  cout << cnt << endl;


  return 0;
}

bool findGW(char word[])
{
  // 단어가 두 글자 이하라면 무조건 true
  if (strlen(word) <= 2)
    return true;
  
  // 일단 대소문자 통일부터 하기 : 대문자로 통일
  for (int i = 0; i < strlen(word); i++)
  {
    if (word[i] >= 'a')
      word[i] = word[i] - 'a' + 'A';
  }

  bool flag = true; // key와 같은 글자가 있다면 참, 기본적으로 참.
  bool changeFlag = false; // 플래그 변화 여부를 저장한다.
  // 플래그가 거짓으로 바뀔 때 이 변수가 참이 된다.
  // flag와 changeFlag가 동시에 참일 경우
  // : key와 연속하지 않은 글자 중에 같은 글자가 있다
  // >> 그룹 문자가 아니므로 거짓을 반환한다.
  for (int i = 0; i < strlen(word); i++) // 반복은 글자 수만큼
  {
    char key = word[i]; // 키 저장
    for (int j = i + 1; j < strlen(word); j++) // 키 이후의 글자에 대하여
    {
      if (key != word[j]) // key와 다른 글자라면 flag와 changeFlag를 수정한다
      {
        flag = false;
        changeFlag = true;
      }
      else if (key == word[j])
      // key와 연속하여 있는 글자이면서 key와 같은 글자라면 flag는 계속 참이고
      // key와 연속한 글자가 아닌데 같은 글자가 나오면 changeFlag가 참인 상태
      {
        flag = true;
      }

      if (changeFlag && flag)
      // flag와 changeFlag가 동시에 참인 경우
        return false;
    }
    // key의 사용이 끝나면 changeFlag를 false로 초기화한다.
    changeFlag = false;
  }

  // 거짓을 반환하지 않고 반복문이 끝났다면 그룹 문자이다.
  return true;
}

