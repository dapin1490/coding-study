// 2022 연세대학교 신학기맞이 프로그래밍 경진대회 Open Contest 참가
// D번 : 시간 내 미제출로 아직 채점 못함

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// 사다리꼴 넓이
double area(double p1[], double p2[]);
// 직선의 기울기
double find_m(double p1[], double p2[]);
// 적분한 직선의 방정식
double FX(double m, double b, double num);
// 회전체 부피 구하기
double answer(double n1, double n2, double n3);

int main()
{
	// 빠른 입출력
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	const double PI = 3.1415926535; // 원주율
	double a[2], b[2], c[2]; // 세 점
	double ab[4], bc[4], ca[4]; // 세 사다리꼴 넓이와 직선의 기울기, 절편, 회전체 부피
	cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];

	// x 축 회전
	// 사다리꼴 넓이
	ab[0] = area(a, b);
	bc[0] = area(b, c);
	ca[0] = area(c, a);
	// 직선의 기울기
	ab[1] = find_m(a, b);
	bc[1] = find_m(b, c);
	ca[1] = find_m(c, a);
	// 절편
	ab[2] = ab[1] * a[0] - a[1];
	bc[2] = bc[1] * b[0] - b[1];
	ca[2] = ca[1] * c[0] - c[1];
	// 회전체 부피
	ab[3] = FX(ab[1], ab[2], max(a[0], b[0])) - FX(ab[1], ab[2], min(a[0], b[0]));
	bc[3] = FX(bc[1], bc[2], max(b[0], c[0])) - FX(bc[1], bc[2], min(b[0], c[0]));
	ca[3] = FX(ca[1], ca[2], max(c[0], a[0])) - FX(ca[1], ca[2], min(c[0], a[0]));
	// x 축 회전 회전체 부피 출력
	cout << answer(ab[3], bc[3], ca[3]) << " ";

	// y 축 회전
	// 좌표 바꾸기
	swap(a[0], a[1]);
	swap(b[0], b[1]);
	swap(c[0], c[1]);
	// 사다리꼴 넓이
	ab[0] = area(a, b);
	bc[0] = area(b, c);
	ca[0] = area(c, a);
	// 직선의 기울기
	ab[1] = find_m(a, b);
	bc[1] = find_m(b, c);
	ca[1] = find_m(c, a);
	// 절편
	ab[2] = ab[1] * a[0] - a[1];
	bc[2] = bc[1] * b[0] - b[1];
	ca[2] = ca[1] * c[0] - c[1];
	// 회전체 부피
	ab[3] = FX(ab[1], ab[2], max(a[0], b[0])) - FX(ab[1], ab[2], min(a[0], b[0]));
	bc[3] = FX(bc[1], bc[2], max(b[0], c[0])) - FX(bc[1], bc[2], min(b[0], c[0]));
	ca[3] = FX(ca[1], ca[2], max(c[0], a[0])) - FX(ca[1], ca[2], min(c[0], a[0]));
	// y 축 회전 회전체 부피 출력
	cout << answer(ab[3], bc[3], ca[3]);

	return 0;
}

// 사다리꼴 넓이
double area(double p1[], double p2[])
{
	return (p1[1] + p2[1]) * abs(p1[0] - p2[0]) / 2;
}

// 직선의 기울기
double find_m(double p1[], double p2[])
{
	return (p2[1] - p1[1]) / (p2[0] - p1[0]);
}

// 적분한 직선의 방정식
double FX(double m, double b, double num)
{
	return m * m * pow(num, 3) / 3 + m * b * pow(num, 2) + b * b * num;
}

// 회전체 부피 구하기
double answer(double n1, double n2, double n3)
{
	if (n1 > n2) {
		if (n1 > n3)
			return n1 - (n2 + n3);
		else
			return n3 - (n1 + n2);
	}
	else {
		if (n2 > n3)
			return n2 - (n1 + n3);
		else
			return n3 - (n1 + n2);
	}
}
