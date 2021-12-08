#include <iostream>
#include <string>
using namespace std;

int main() {

  //Please Enter Your Code Here
  string text;
  cin >> text;
  
  string arran = "";
  
  for (int j = 0; j < text.length(); j++)
  {
    for (int k = 0; k < text.length(); k++)
    {
      if (text.at(j) == text.at(k) && j < k)
        text.at(k) = ' ';
    }
  }
  
  for (int m = 0; m < text.length(); m++)
  {
    if (text.at(m) != ' ')
      arran += text.at(m);
  }
  
  cout << arran;

  return 0;
}
