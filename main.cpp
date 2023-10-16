#define _CRT_SECURE_NO_WARNINGS 1

#include "Person.hpp"
#include "system.hpp"

int main()
{
	int tmp = 0;
	while (1)
	{
		cout << "欢迎来到火车购票系统" << endl;
		cout << " 1.进入    0.退出 " << endl;
		cout << "请选择>:";
		cin >> tmp;
		clear();
		if (tmp > 1 || tmp < 0)
		{
			system("cls");
			cout << "选择错误请重新选择：>" << endl;
			continue;
		}
		if (tmp == 1)
		{
			Enter_system(tmp);
		}
		if (tmp == 0)
		{
			cout << "********感谢您的使用*********" << endl;
			break;
		}
	}
	return 0;
}