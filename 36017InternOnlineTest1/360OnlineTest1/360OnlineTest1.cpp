// 360OnlineTest1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

#define PI 3.141

void Coordinate(int L, int R)
{
	float lenght = 2 * PI* R;
	int circle = (float)L / lenght;
	float arc = (float)L - (circle * lenght);
	float angle = arc / R;

	float clockwise_y = -(R * sin(angle));
	float clockwise_x = (R * cos(angle));
	float anticlock_y = (R * sin(angle));
	float anticlock_x = (R * cos(angle));
	printf("%.3f ", clockwise_x);
	printf("%.3f ", clockwise_y);
	printf("\n");
	printf("%.3f ", anticlock_x);
	printf("%.3f ", anticlock_y);
	//cout << setprecision(3) << clockwise_x << " " << clockwise_y << endl;
	//cout << setprecision(3) << anticlock_x << " " << anticlock_y << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int L, R;
	while (cin >> L)
	{
		cin >> R;
		Coordinate(L, R);
	}

	system("pause");
	return 0;
}

