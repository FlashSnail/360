// 360MemoryManage.cpp : �������̨Ӧ�ó������ڵ㡣
/*�о�С��ƻ�����һ��ʵ�����ڴ��������ʵ�ֶ��ڴ�ķ��䡢�ͷź�������Ӧ�Ľӿ�Ϊnew��del��def��ʹ���﷨Ϊ��
new size������size�ֽڴ�С���ڴ�飬���ظ��ڴ��ľ��handle��sizeΪ��������
del handle���ͷž��handleָ����ڴ�飻
def�������ڴ���Ƭ���������ѷ����ڴ�鰴��ַ�ӵ͵��ߵ�˳��Ǩ�ƣ�ʹ�����ڴ���Ƭ�ڸߵ�ַ��ƴ����һ��
��ʼ�ڴ�Ϊ initSize �ֽڴ�С����Ƭ�����ڴ棬���Ϊ 1 �� initSize ��
new size�����У������ڲ�С��size�����������ڴ棬����С��ַ���ȵ�ԭ��ӿ����ڴ������з���size��С���ڴ�飬
��Ǹ��ڴ��״̬Ϊ�ѷ��䣬������ָ����ڴ��ľ�������޷����䣬�򷵻ؿգ�NULL����
del handle�����ͷ���handle��ǵ��ڴ�飬��Ǳ��ͷŵ��ڴ�״̬Ϊ���С���handleΪ��Ч������򷵻�ILLEGAL_OPERATION��
def ����ڴ����������޷���ֵ��
������ƣ�ÿ�γɹ��ڴ���䷵�صľ��Ϊһ������������1��ʼ�����μ�����ʧ�ܵĴ洢���������Ӱ�������*/

/*����
�������ж���������ݡ�ÿ��������ݵĵ�һ��Ϊ����������T��MaxMem��1<=T<=10000, 1<=MaxMem<=10000����
����TΪ����������MaxMemΪ��ʼ�ڴ��С�������T�в���ָ�
��������
6 10
new 5
new 3
del 1
new 6
def
new 6
���
��ÿ��������ݣ�������˳����������������ÿ��new�������ڵ����������������ɹ�ʱ����䷵�ؾ��ֵ��
ʧ�������NULL����del����ʧ�ܣ����ILLEGAL_OPERATION��def�����������
�������
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
			 while (pos_end < size - 1)	//ȫ���������ڴ�
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

