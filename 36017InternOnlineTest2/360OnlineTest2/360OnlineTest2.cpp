// 360OnlineTest1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

void CutBallon(int num, int *ballon)
{
	cout << "I Have No Time To Cut These Ballons!!!!" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int num = 0;
	int index = 0;
	while (cin>>num)
	{
		int *ballon = new int[num];
		cin >> ballon[index];
		index++;
		CutBallon(num, ballon);
	}

	system("pause");
	return 0;
}

