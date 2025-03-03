#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 전투력 계산
double calcpower(int c);

vector<vector<double>> call;
double comp[4] = { 0 }; // (사람, 무기) 순서대로 크리크리, 크리파부, 파부크리, 파부파부

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<double> cri;
	vector<double> pabu;

	for (int i = 0; i < 20; i++) {
		double num;
		cin >> num;
		switch (i / 5)
		{
		case 0: case 2:
			cri.push_back(num);
			break;
		case 1: case 3:
			pabu.push_back(num);
			break;
		}
	}

	call.push_back(cri);
	cri.clear();
	call.push_back(pabu);
	pabu.clear();
	for (int i = 2; i <= 4; i++) {
		call[0][i] *= 0.01;
		call[0][i + 5] *= 0.01;
		call[1][i] *= 0.01;
		call[1][i + 5] *= 0.01;
	}

	for (int i = 0; i < 4; i++)
		comp[i] = calcpower(i);

	int cri_up = 0;
	int pabu_up = 0;
	if (comp[0] > comp[1])
		cri_up = -1;
	else if (comp[0] < comp[1])
		cri_up = 1;
	if (comp[2] < comp[3])
		pabu_up = -1;
	else if (comp[2] > comp[3])
		pabu_up = 1;

	switch (cri_up)
	{
	case -1:
		cout << "-\n";
		break;
	case 0:
		cout << "0\n";
		break;
	case 1:
		cout << "+\n";
		break;
	}

	switch (pabu_up)
	{
	case -1:
		cout << "-\n";
		break;
	case 0:
		cout << "0\n";
		break;
	case 1:
		cout << "+\n";
		break;
	}

	return 0;
}

// 전투력 계산
double calcpower(int c)
{
	// (사람, 무기) 순서대로 크리크리, 크리파부, 파부크리, 파부파부
	double stat[5] = { 0 };

	for (int i = 0; i <= 4; i++) {
		stat[i] = call[c / 2][i] - call[c / 2][i + 5] + call[c % 2][i + 5]; // 왼쪽은 사람, 오른쪽은 무기 스탯
	}

	double ans = stat[0] * (1 + stat[1] / 100) * ((1 - min(stat[2], 1.0)) + min(stat[2], 1.0) * stat[3]) * (1 + stat[4]);
	return ans;
}
