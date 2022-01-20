#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	
	int n;
	cin >> n;
	int div = 2;
	
	while (n != 1)
	{
	    if (n % div == 0)
	    {
	        v.push_back(div);
	        n /= div;
	    }
	    else
	        div++;
	}
	
	for (int i = 0; i < v.size(); i++)
	    cout << v.at(i) << "\n";
	
	return 0;
}
