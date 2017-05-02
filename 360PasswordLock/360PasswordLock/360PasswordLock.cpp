// 360PasswordLock.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
using namespace std;


string CenterSymmetry(char x[][3])
{
	if ((x[0][0] != x[2][2]) || (x[0][1] != x[2][1]) || (x[0][2] != x[2][0]) || (x[1][0] != x[1][2]))
	{
		return "NO";
	}
	else
	{
		return "YES";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[3][3];
	int i = 0, j = 0;
	while (cin >> a[0])
	{
		cin >> a[1];
		cin >> a[2];
		cout << CenterSymmetry(a) << endl;
	}
	system("pause");
	return 0;
}

