#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
static const string arr[16] = { "������վ", "����վ", "����վ", "����վ", "ʯ��ׯվ", "̫ԭվ", "���ͺ���վ","����վ","����վ","��³ľ��վ","����վ","����վ","����վ","����վ","����վ","����վ" };
static const string brr[16] = { "����վ","���վ","����վ","�Ϸ�վ","�Ͼ�վ","�Ϻ�վ","����վ","����վ","����վ" };
static const string crr[16] = { "����վ","ʯ��ׯվ","֣��վ","����վ","�ɶ�վ","����վ","��ɳվ","����վ" };
static const string drr[16] = { "֣��վ","�人վ","�ϲ�վ","����վ" };

class train
{
public:
	train(int number)
	{
		this->number = number;
		switch (number)
		{
		case 1:
			this->_arr = arr;
			break;
		case 2:
			this->_arr = brr;
			break;
		case 3:
			this->_arr = crr;
			break;
		case 4:
			this->_arr = drr;
			break;
		}

	}

	void test()
	{
		cout << number << "�Ż�:";
		for (int i = 0; i < 16; i++)
		{
			cout << this->_arr[i] << " ";
		}

		cout << endl;
	}
	void showticket()
	{
		switch (ticketnumber)
		{
		case 1:
			cout << "��Ϊ��׼��������" << endl;
			this->ticketprice = 60;
			break;
		case 2:
			cout << "��Ϊ��׼����Ӳ��" << endl;
			this->ticketprice = 45;
			break;
		case 3:
			cout << "��Ϊ��׼����һ����" << endl;
			this->ticketprice = 30;
			break;
		case 4:
			cout << "��Ϊ��׼���ö�����" << endl;
			this->ticketprice = 20;
			break;
		case 5:
			cout << "��Ϊ��׼����վƱ" << endl;
			this->ticketprice = 15;
			break;
		}
	}
	const string* _arr;
	int number;
	int ticketnumber;
	int ticketprice;
	//const string* _arr;
};