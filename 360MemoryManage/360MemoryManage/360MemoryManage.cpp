// 360MemoryManage.cpp : 定义控制台应用程序的入口点。
/*研究小组计划开发一个实验性内存管理器，实现对内存的分配、释放和整理。对应的接口为new、del和def，使用语法为：
new size：分配size字节大小的内存块，返回该内存块的句柄handle，size为正整数；
del handle：释放句柄handle指向的内存块；
def：整理内存碎片，将所有已分配内存块按地址从低到高的顺序迁移，使空闲内存碎片在高地址端拼接在一起；
初始内存为 initSize 字节大小的整片空闲内存，编号为 1 到 initSize 。
new size操作中，若存在不小于size的连续空闲内存，则按照小地址优先的原则从空闲内存区域中分配size大小的内存块，
标记该内存块状态为已分配，并返回指向该内存块的句柄。若无法分配，则返回空（NULL）。
del handle操作释放由handle标记的内存块，标记被释放的内存状态为空闲。若handle为无效句柄，则返回ILLEGAL_OPERATION。
def 完成内存整理工作，无返回值。
根据设计，每次成功内存分配返回的句柄为一个正整数，从1开始，依次计数。失败的存储分配操作不影响计数。*/

/*输入
输入中有多组测试数据。每组测试数据的第一行为两个正整数T和MaxMem（1<=T<=10000, 1<=MaxMem<=10000），
其中T为操作次数，MaxMem为初始内存大小，随后有T行操作指令。
样例输入
6 10
new 5
new 3
del 1
new 6
def
new 6
输出
对每组测试数据，按操作顺序输出操作结果。对每个new操作，在单独行中输出结果，成功时输出其返回句柄值，
失败则输出NULL。若del操作失败，输出ILLEGAL_OPERATION。def不产生输出。
样例输出
1
2
NULL
3*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void MemoryManage(int times, int size, int *Memory)
{
	string *Operate = new string[size]();

	int _new = 0, _del = 0, def = 0;	//0: Do Nothing; >=1: Do;
	string type;
	int handle_num = 0;
	int *handle_begin = new int[size]();
//	handle_begin = { 0 };
	int *handle_end = new int[size]();
//	handle_end = { 0 };
	int *free = new int[size]();
//	free = { 0 };
	int num = -1;
	int pos_begin = 0;
	int pos_end = 0;
	int *free_begin = new int[size]();
	int *free_end = new int[size]();
	for (int i = 0; i < times; i++)
	{
		 cin >> Operate[i];
		 type = Operate[i];
	//==========================================================
		 if (type == "new")
		 {
			 cin >> _new;
			 pos_end = 0;
			 while (pos_end < size - 1)	//全遍历空余内存
			 {
				 for (int i = pos_end; i < size; i++)
				 {
					 if (Memory[i] == 0)
					 {
						 num++;
						 pos_begin = i;
						 free_begin[num] = pos_begin;
						 break;
					 }
				 }
				 for (int i = pos_begin; i < size; i++)
				 {
					 if (Memory[i] == 0)
					 {
						 free[num]++;
					 }
					 else
					 {
						 pos_end = i;
						 free_end[num] = pos_end;
					//	 pos_end = 0;
						 break;
					 }
					 if (i == size - 1)
					 {
						 pos_end = i;
						 free_end[num] = pos_end;
						// pos_end = 0;
						 break;
					 }
				 }
			 }
			 
			 for (int i = 0; i <= num; i++)
			 {
				 if (_new <= free[i])
				 {
					 handle_num++;
					 for (int j = free_begin[i]; j < free_begin[i] + _new; j++)
					 {
						 Memory[j] = 1;
					 }
					 handle_begin[handle_num] = free_begin[i];
					 handle_end[handle_num] = free_begin[i] + _new;
					 free[i] = 0;
					 cout << handle_num << endl;
					 break;
				 }
				 if (i == num)
				 {
					 cout << "NULL" << endl;
				 }
			 }			
		 }
	//==========================================================
		 else if (type == "del")
		 {
			 cin >> _del;
			 if (_del > handle_num)
			 {
				 cout << "ILLEGAL_OPERATION" << endl;
			 }
			 else
			 {
				 for (int i = handle_begin[_del]; i < handle_end[_del]; i++)
				 {
					 Memory[i] = 0;
					 handle_begin[_del] = 0;
					 handle_end[_del] = 0;
				 }
		//		 handle_num--;
			 }
		 }
	//==========================================================
		 else   //def
		 {
			 def = 1;	//0: Do Nothing; 1: Do
			 for (int i = 0; i < size; i++)
			 {
				 Memory[i] = 0;
			 }
			 for (int i = 1; i <= handle_num; i++)
			 {
				 for (int j = handle_end[i - 1]; j < handle_end[i] - handle_begin[i]; j++)
				 {
					 Memory[j] = 1;
				 }
			 }
		 }
	}
	//==========================================================
}

int _tmain(int argc, _TCHAR* argv[])
{
	int times;
	int size;	
	while (cin>> times >> size)
	{
		int *Memory = new int[size]();
		MemoryManage(times, size, Memory);
	}
	return 0;
}

