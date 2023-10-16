#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
static const string arr[16] = { "哈尔滨站", "长春站", "沈阳站", "北京站", "石家庄站", "太原站", "呼和浩特站","银川站","西宁站","乌鲁木齐站","拉萨站","昆明站","贵阳站","南宁站","广州站","海南站" };
static const string brr[16] = { "北京站","天津站","济南站","合肥站","南京站","上海站","杭州站","福州站","广州站" };
static const string crr[16] = { "北京站","石家庄站","郑州站","西安站","成都站","重庆站","长沙站","广州站" };
static const string drr[16] = { "郑州站","武汉站","南昌站","广州站" };

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
		cout << number << "号火车:";
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
			cout << "已为您准备好软卧" << endl;
			this->ticketprice = 60;
			break;
		case 2:
			cout << "已为您准备好硬卧" << endl;
			this->ticketprice = 45;
			break;
		case 3:
			cout << "已为您准备好一等座" << endl;
			this->ticketprice = 30;
			break;
		case 4:
			cout << "已为您准备好二等座" << endl;
			this->ticketprice = 20;
			break;
		case 5:
			cout << "已为您准备好站票" << endl;
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