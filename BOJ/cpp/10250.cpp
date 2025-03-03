#include <iostream>
#include <string>
using namespace std;

string findRoom(int h, int w, int n);

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int h, w, n;
		cin >> h >> w >> n;

		cout << findRoom(h, w, n) << "\n";
	}
	
	
	return 0;
}

string findRoom(int h, int w, int n)
{
	int line = 1;
	int address = h;

	while (n > address)
	{
		address += h;
		line++;
	}

	if (line > w)
		return "There is no room.";
	
	int xx = line;
	int yy = h - (address - n);
	string room;

	if (xx < 10)
		room = to_string(yy) + "0" + to_string(xx);
	else
		room = to_string(yy) + to_string(xx);

	return room;
}
