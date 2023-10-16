#pragma once
#include "Person.hpp"
#include "train.hpp"
#include <list>
#include <cassert>
#define PERSON_FILE "person.txt"

void load_file(list<Person>& lt)
{
	FILE* pr = fopen(PERSON_FILE, "r");
	assert(pr);
	Person p;
	char buffer[128] = { 0 };
	while (1)
	{
		if (fscanf(pr, "%s", buffer) != EOF)
			p._id = buffer;
		else
			break;
		if (fscanf(pr, "%s", buffer) != EOF)
			p._name = buffer;
		else
			break;
		if (fscanf(pr, "%s", buffer) != EOF)
			p._phone_id = buffer;
		else
			break;
		if (fscanf(pr, "%s", buffer) != EOF)
			p._password = buffer;
		else
			break;
		lt.push_back(p);
	}
	fclose(pr);
	pr = NULL;
}

void clear()
{
	while (getchar() != '\n');
}

void show_person(const Person& p)
{
	cout << "您的身份证号为:" << p._id << endl;
	cout << "您的姓名为:" << p._name << endl;
	cout << "您的电话号码为:" << p._phone_id << endl;
	cout << "您的密码为:" << p._password << endl;
}

void write_to_file(list<Person>& lt)
{
	FILE* pw = fopen(PERSON_FILE, "w");
	assert(pw);
	for (auto e : lt)
	{
		fprintf(pw, " %s", e._id.c_str());
		fprintf(pw, " %s", e._name.c_str());
		fprintf(pw, " %s", e._phone_id.c_str());
		fprintf(pw, " %s", e._password.c_str());
	}
	fclose(pw);
	pw = NULL;
}

void save_person(Person& p)
{
	system("cls");
	string tmp;
	cout << "请输入您的身份证号:>";
	cin >> tmp;
	p._id = tmp;
	clear();
	cout << "请输入您的姓名:>";
	cin >> tmp;
	p._name = tmp;
	clear();
	cout << "请输入您的手机号:>";
	cin >> tmp;
	p._phone_id = tmp;
	clear();
	while (1)
	{
		cout << "请输入您的密码:>";
		cin >> tmp;
		p._password = tmp;
		clear();
		cout << "请再次输入您的密码:>";
		cin >> tmp;
		clear();
		if (tmp == p._password) break;
		else cout << "*********您输入的密码不正确请重新输入********" << endl;
	}
}

void sign_in(Person& p)
{
	save_person(p);
	system("cls");
	cout << "您的注册信息如下:" << endl;
	show_person(p);
	cout << "恭喜您已成功注册" << endl;
	system("pause");
}

void log_in(Person& p, const list<Person>& lt)
{
	while (1)
	{
		int flag = 0;
		cout << "请输入您的手机号:>";
		cin >> p._phone_id;
		clear();
		cout << "请输入您的密码:>";
		cin >> p._password;
		clear();
		for (auto e : lt)
		{
			if (p._phone_id == e._phone_id && p._password == e._password)
			{
				flag = 1;
				p = e;
				break;
			}
		}
		if (flag == 1) break;
		else cout << "您输入的手机号或密码有误请重新输入:>" << endl;
	}
	cout << "恭喜您已成功登录" << endl;
	system("pause");
}

void Show_train()
{
	train s1(1);
	system("cls");
	//s1.printvector();
	s1.test();
	train s2(2);
	s2.test();
	train s3(3);
	s3.test();
	train s4(4);
	s4.test();
	system("pause");
}

void Order_tickets()
{
	Show_train();
	cout << "请选择要乘坐的火车" << endl;
	int _choice;
	cin >> _choice;
	train s(_choice);

	cout << "接下来请输入您要乘坐的区间" << endl;
	string s_begin;
	string s_end;
	cout << "请先输入起始站" << endl;
	cin >> s_begin;
	cout << "接下来输入终点站" << endl;
	cin >> s_end;
	int begin;
	int end;
	for (int i = 0; i < 16; i++)
	{
		if (s._arr[i] == s_begin)
		{
			begin = i;

		}
		if (s._arr[i] == s_end)
		{
			end = i;
		}
	}
	cout << "确认您的路线为" << s._arr[begin] << "-" << s._arr[end] << "," << "一共" << abs(end - begin) << "站" << endl;
	cout << "选择您的票型:1.软卧,2.硬卧,3.一等座,4.二等座,5.站票" << endl;;
	int _ticketnumber;
	cin >> _ticketnumber;
	s.ticketnumber = _ticketnumber;
	s.showticket();
	cout << "票价为" << abs((end - begin)) * (s.ticketprice) << endl;

	system("pause");
}

void Cancel_ticket()
{
	cout << "Cancel_ticket()" << endl;

	system("pause");
}

void show_information(Person& p)
{
	system("cls");
	show_person(p);
	while (1)
	{
		int choose = 0;
		cout << "您是否需要修改您的身份信息" << endl;
		cout << "1.修改     0.不修改" << endl;
		cout << "请选择您要进行的操作：>";
		cin >> choose;
		if (choose > 1 || choose < 0)
		{
			system("cls");
			cout << "选择错误请重新选择：>" << endl;
			continue;
		}
		if (choose == 0) break;
		if (choose == 1)
		{
			save_person(p);
			system("cls");
			cout << "您修改后的信息如下:" << endl;
			show_person(p);
			cout << "您已成功修改" << endl;
			break;
		}
	}
	system("pause");
}

void Enter_system(int& tmp)
{
	Person p;
	list<Person> lt;
	load_file(lt);
	while (1)
	{
		int choose = 0;
		system("cls");
		cout << "***************************" << endl;
		cout << "1.注册       2.登录" << endl;
		cout << "      0.退出      " << endl;
		cout << "请选择您要进行的操作：>";
		cin >> choose;
		clear();
		if (choose > 2 || choose < 0)
		{
			system("cls");
			cout << "选择错误请重新选择：>" << endl;
			continue;
		}
		if (choose == 0)
		{
			tmp = 0;
			break;
		}
		if (choose == 1)
		{
			sign_in(p);
			lt.push_back(p);
			break;
		}
		if (choose == 2)
		{
			system("cls");
			log_in(p,lt);
			break;
		}
	}
	if (tmp == 0) return;
	while (1)
	{
		int choose = 0;
		system("cls");
		cout << "***************************" << endl;
		cout << "1.查询列车情况  2.订购车票" << endl;
		cout << "3.退订车票     4.查看个人信息" << endl;
		cout << "     0.退出系统" << endl;
		cout << "请选择您要进行的操作：>";  
		cin >> choose;
		clear();
		if (choose > 4 || choose < 0)
		{
			system("cls");
			cout << "选择错误请重新选择：>" << endl;
			continue;
		}
		switch (choose)
		{
		case 0:
		{
			tmp = 0;
			break;
		}
		case 1:
		{
			Show_train();
			break;
		}
		case 2:
		{
			Order_tickets();
			break;
		}
		case 3:
		{
			Cancel_ticket();
			break;
		}
		case 4:
		{
			show_information(p);
			break;
		}
		}
		if (tmp == 0) break;
	}
	write_to_file(lt);
}