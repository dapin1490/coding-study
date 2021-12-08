// 영어 대소문자와 숫자, 특수기호, 그리고 공백으로 이루어진 문자열이 주어진다.
// 이 문자열 안에 몇 개의 단어, 몇 개의 숫자 단어(숫자로만 이루어진 단어),
// 몇 개의 특수기호(!, ?, 따옴표(“), 쉼표(,), 마침표(.), &, -, ~)가 있는지 구하는 프로그램을 작성하세요.
// 단어는 공백으로 구분 지어진 문자열을 의미하며 단어의 개수에서 숫자 단어를 포함하지 않아야 하고,
// 한 단어가 여러 번 등장해도 등장한 횟수만큼 세어야 한다.
// 특수기호의 경우, 다른 단어 안에 속해 있거나 별도로 독립적인 경우에나 특수기호가 등장할 때마다 세어야 한다.

// 조건
// 문자열의 길이는 1,000을 넘지 않는다.
// 단어는 공백 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다.

#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int findMark(const char array[]); // 특수문자 세기

int main() {

  // word 플래그, nums 플래그 두고
  // 앞에서부터 for 안에 if 돌리는데
  // word = true면 words++ nums = true면 numb++
  // 근데 word = true && nums = true면 words++,
  // 공백 나오면 플래그 상태에 따라 증감 후 플래그 초기화
  
  char text[1000]; // 개수를 셀 텍스트를 받음
  cin.getline(text, 1001);
  
  bool word = false, numb = false; // 각각 단어, 숫자 플래그
  int words = 0, numbs = 0; // 단어 개수와 숫자 개수 저장할 변수
  
  for (int i = 0; i < strlen(text); i++) // 반복은 텍스트 길이 만큼
  {
    if (text[i] != ' ') // text[i]가 공백이 아닐 때 : 단어 중 한 글자일 때
    {
      if (text[i] < '0' || text[i] > '9')
      {
        // text[i]가 숫자가 아님 == 단어이다
        word = true;
        numb = false;
      }
      else if (text[i] >= '0' && text[i] <= '9')
      {
        // text[i]가 숫자임 == 숫자일 수 있다
        numb = true;
      }
    }
    
    if (text[i] == ' ' || (i == strlen(text) - 1))
      // text[i]가 공백일 때 : 한 단어가 끝남
      // 또는 마지막 글자일 때
    {
      if ((word && numb) || word)
      {
        // word와 numb가 모두 참인 경우 : 숫자에 문자 또는 특수문자가 섞인 단어
        // word만 참인 경우 : 숫자가 섞이지 않은 단어
        words++;
        // 다음 단어를 검사하기 위해 플래그 변수 초기화
        word = false;
        numb = false;
      }
      else if (numb)
      {
        // 문자 또는 특수문자가 섞이지 않은 순수 숫자만 숫자로 취급한다
        numbs++;
        // 다음 단어를 검사하기 위해 플래그 변수 초기화
        word = false;
        numb = false;
      }
    }
  }
  

  // 아스키코드
  // 특수문자 : 47 이하, 58 ~ 64, 91 ~ 96, 123 ~ 126
  // 숫자 : 48 ~ 57
  // 영대문자 : 65 ~ 90
  // 영소문자 : 97 ~ 122

  // 단어 : 숫자 제외 나머지
  // 숫자 : 순수 숫자만
  // 특수문자 : 어디에 있든 등장할 때마다 포함

  // 첫째 줄에 단어의 개수, 둘째 줄에 숫자의 개수, 셋째 줄에 특수기호의 개수를 출력한다.
  
  std::cout << words << endl;
  std::cout << numbs << endl;
  std::cout << findMark(text) << endl;
  

  return 0;
}

int findMark(const char array[])
{
  int mark = 0; // 특수문자 개수 저장

  for (int i = 0; i < strlen(array); i++)
  {
    if (array[i] < '0' || (array[i] > '9' && array[i] < 'A') || (array[i] > 'Z' && array[i] < 'a') || array[i] > 'z')
    {
      if (array[i] != ' ')
        // 특수문자이되 공백이 아닌 경우에만 개수 증가
        mark++;
    }
  }

  return mark;
}


