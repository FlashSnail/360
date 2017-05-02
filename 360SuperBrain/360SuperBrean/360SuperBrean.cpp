// 360SuperBrean.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void Direction(string trace, string first, string second)
{
	int first_pos = string::npos;
	int second_pos = string::npos;
	bool forward = false;
	bool backward = false;

	first_pos = trace.find(first);
	if (first_pos != string::npos)
	{
		second_pos = trace.find(second, first_pos + first.length());
	}
	if (second_pos != string::npos)
	{
		forward = true;
	}

	first_pos = string::npos;
	second_pos = string::npos;

	first_pos = trace.rfind(first);
	if (first_pos != string::npos)
	{
		if (first_pos - 1 < 0)
		{
			second_pos = string::npos;
		}
		else if (first_pos - 1 == 0)
		{
			if (second.length() == 1)
			{
				second_pos = trace.rfind(second, first_pos - 1);
			}
		}
		else
		{
			if (first_pos + 1 <= second.length())
			{
				second_pos = -1;
			}
			else
			{
				second_pos = trace.rfind(second, first_pos - 1);
			}			
		}		
	}	
	if (second_pos != string::npos)
	{
		backward = true;
	}

	if (forward == true && backward == false)
	{
		cout << "forward" << endl;
	}
	if (backward == true && forward == false)
	{
		cout << "backward" << endl;
	}
	if (forward && backward)
	{
		cout << "both" << endl;
	}
	if (backward == false && forward == false)
	{
		cout << "invalid" << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	string trace;
	string first;
	string second;
	while (cin >> trace)
	{
		cin >> first;
		cin >> second;
		Direction(trace, first, second);
	}
	return 0;
}

