#include <iostream>
using namespace std;

int euclidean(int big, int small);

int main() { 
	
	int a, b;
	cout << "두 수 입력 : ";
	cin >> a >> b;
	cout << "\n" << a << "와 " << b << "의 최대공약수는 " << euclidean(a, b) << "이다." << endl;

	
	return 0;
}

int euclidean(int big, int small)
{
	int last = 1; // 매 연산마다 나머지를 저장함
  
	while (last != 0)
	{
		if (big % small == 0)
			break;
		last = big % small;
		big = small;
		small = last;
	}
	
	return last;
}


