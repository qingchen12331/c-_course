#define _CRT_SECURE_NO_WARNINGS 1

#include "Person.hpp"
#include "system.hpp"

int main()
{
	int tmp = 0;
	while (1)
	{
		cout << "��ӭ�����𳵹�Ʊϵͳ" << endl;
		cout << " 1.����    0.�˳� " << endl;
		cout << "��ѡ��>:";
		cin >> tmp;
		clear();
		if (tmp > 1 || tmp < 0)
		{
			system("cls");
			cout << "ѡ�����������ѡ��>" << endl;
			continue;
		}
		if (tmp == 1)
		{
			Enter_system(tmp);
		}
		if (tmp == 0)
		{
			cout << "********��л����ʹ��*********" << endl;
			break;
		}
	}
	return 0;
}