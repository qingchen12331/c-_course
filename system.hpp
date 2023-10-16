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
	cout << "�������֤��Ϊ:" << p._id << endl;
	cout << "��������Ϊ:" << p._name << endl;
	cout << "���ĵ绰����Ϊ:" << p._phone_id << endl;
	cout << "��������Ϊ:" << p._password << endl;
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
	cout << "�������������֤��:>";
	cin >> tmp;
	p._id = tmp;
	clear();
	cout << "��������������:>";
	cin >> tmp;
	p._name = tmp;
	clear();
	cout << "�����������ֻ���:>";
	cin >> tmp;
	p._phone_id = tmp;
	clear();
	while (1)
	{
		cout << "��������������:>";
		cin >> tmp;
		p._password = tmp;
		clear();
		cout << "���ٴ�������������:>";
		cin >> tmp;
		clear();
		if (tmp == p._password) break;
		else cout << "*********����������벻��ȷ����������********" << endl;
	}
}

void sign_in(Person& p)
{
	save_person(p);
	system("cls");
	cout << "����ע����Ϣ����:" << endl;
	show_person(p);
	cout << "��ϲ���ѳɹ�ע��" << endl;
	system("pause");
}

void log_in(Person& p, const list<Person>& lt)
{
	while (1)
	{
		int flag = 0;
		cout << "�����������ֻ���:>";
		cin >> p._phone_id;
		clear();
		cout << "��������������:>";
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
		else cout << "��������ֻ��Ż�������������������:>" << endl;
	}
	cout << "��ϲ���ѳɹ���¼" << endl;
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
	cout << "��ѡ��Ҫ�����Ļ�" << endl;
	int _choice;
	cin >> _choice;
	train s(_choice);

	cout << "��������������Ҫ����������" << endl;
	string s_begin;
	string s_end;
	cout << "����������ʼվ" << endl;
	cin >> s_begin;
	cout << "�����������յ�վ" << endl;
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
	cout << "ȷ������·��Ϊ" << s._arr[begin] << "-" << s._arr[end] << "," << "һ��" << abs(end - begin) << "վ" << endl;
	cout << "ѡ������Ʊ��:1.����,2.Ӳ��,3.һ����,4.������,5.վƱ" << endl;;
	int _ticketnumber;
	cin >> _ticketnumber;
	s.ticketnumber = _ticketnumber;
	s.showticket();
	cout << "Ʊ��Ϊ" << abs((end - begin)) * (s.ticketprice) << endl;

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
		cout << "���Ƿ���Ҫ�޸����������Ϣ" << endl;
		cout << "1.�޸�     0.���޸�" << endl;
		cout << "��ѡ����Ҫ���еĲ�����>";
		cin >> choose;
		if (choose > 1 || choose < 0)
		{
			system("cls");
			cout << "ѡ�����������ѡ��>" << endl;
			continue;
		}
		if (choose == 0) break;
		if (choose == 1)
		{
			save_person(p);
			system("cls");
			cout << "���޸ĺ����Ϣ����:" << endl;
			show_person(p);
			cout << "���ѳɹ��޸�" << endl;
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
		cout << "1.ע��       2.��¼" << endl;
		cout << "      0.�˳�      " << endl;
		cout << "��ѡ����Ҫ���еĲ�����>";
		cin >> choose;
		clear();
		if (choose > 2 || choose < 0)
		{
			system("cls");
			cout << "ѡ�����������ѡ��>" << endl;
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
		cout << "1.��ѯ�г����  2.������Ʊ" << endl;
		cout << "3.�˶���Ʊ     4.�鿴������Ϣ" << endl;
		cout << "     0.�˳�ϵͳ" << endl;
		cout << "��ѡ����Ҫ���еĲ�����>";  
		cin >> choose;
		clear();
		if (choose > 4 || choose < 0)
		{
			system("cls");
			cout << "ѡ�����������ѡ��>" << endl;
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