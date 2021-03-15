#include<iostream>
#include<string>
#include"qi.h"
#include<stdlib.h>
#include"windows.h"
using namespace std;

Qizi::Qizi(string name, string color) :name(name), color(color) {}
//����ʵ��
Che::Che(string color) : Qizi("��", color) {}
int Che::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10)
	{
		cout << "����Խ��,";
		return 0;
	}
	else
	{
		int i;
		//��㡢�յ㲻��ͬһ��ֱ����
		if ((start_x != end_x) && (start_y != end_y))
		{
			cout << "��������ֱ��,";
			return 0;
		}
		//�����ƶ�ʱ���м��Ƿ������ӡ�
		if (start_x == end_x)
		{
			if (start_y < end_y)
			{
				for (i = start_y + 1; i < end_y; i++)
					if (qp.q[start_x][i]->name != "   ")
					{
						cout << "ˮƽ��·��������,";
						return 0;
					}
			}
			else
			{
				for (i = end_y + 1; i < start_y; i++)
					if (qp.q[start_x][i]->name != "   ")
					{
						cout << "ˮƽ��·��������,";
						return 0;
					}
			}
		}
		//�����ƶ�ʱ���м��Ƿ������ӡ�
		if (start_y == end_y)
		{
			if (start_x < end_x)
			{
				for (i = start_x + 1; i < end_x; i++)
					if (qp.q[i][start_y]->name != "   ")
					{
						cout << "��ֱ��·��������,";
						return 0;
					}
			}
			else
			{
				for (i = end_x + 1; i < start_x; i++)
					if (qp.q[i][start_y]->name != "   ")
					{
						cout << "��ֱ��·��������,";
						return 0;
					}
			}
		}
		return 1;
	}

}
//���ʵ��
Ma::Ma(string color) :Qizi("��", color) {}
int Ma::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10)
	{
		cout << "����Խ��,";
		return 0;
	}
	else
	{
		if (end_y == start_y + 2)
		{
			if (end_x == start_x + 1 || end_x == start_x - 1)
			{
				if (qp.q[start_x][start_y + 1]->name != "   ")
				{
					cout << "�޷��ƶ�,";
					return 0;
				}
				else
					return 1;
			}
			else
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
		if (end_y == start_y - 2)
		{
			if (end_x == start_x + 1 || end_x == start_x - 1)
			{
				if (qp.q[start_x][start_y - 1]->name != "   ")
				{
					cout << "�޷��ƶ�,";
					return 0;
				}
				else
					return 1;
			}
			else
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
		if (end_x == start_x + 2)
		{
			if (end_y == start_y + 1 || end_y == start_y - 1)
			{
				if (qp.q[start_x + 1][start_y]->name != "   ")
				{
					cout << "�޷��ƶ�,";
					return 0;
				}
				else
					return 1;
			}
			else
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
		if (end_x == start_x - 2)
		{
			if (end_y == start_y + 1 || end_y == start_y - 1)
			{
				if (qp.q[start_x - 1][start_y]->name != "   ")
				{
					cout << "�޷��ƶ�,";
					return 0;
				}
				else
					return 1;
			}
			else
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
	}
	return 0;
}


//�ڵ�ʵ��
Pao::Pao(string color) :Qizi("��", color) {}
int Pao::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10)
	{
		cout << "����Խ��,";
		return 0;
	}
	else
	{
		if (end_x != start_x && end_y != start_y)
		{
			cout << "�ڱ�����ֱ��,";
			return 0;
		}
		if (end_x > start_x)
		{
			int count = 0;
			for (int i = start_x + 1; i <= end_x; i++)
				if (qp.q[i][start_y]->name != "   ")
					count++;
			if (count != 2 && count != 0)
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
		if (end_x < start_x)
		{
			int count = 0;
			for (int i = start_y - 1; i >= end_x; i--)
				if (qp.q[i][start_y]->name != "   ")
					count++;
			if (count != 2 && count != 0)
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
		if (end_y > start_y)
		{
			int count = 0;
			for (int i = start_y + 1; i <= end_y; i++)
				if (qp.q[start_x][i]->name != "   ")
					count++;
			if (count != 2 && count != 0)
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
		if (end_y < start_y)
		{
			int count = 0;
			for (int i = start_y - 1; i >= end_y; i--)
				if (qp.q[start_x][i]->name != "   ")
					count++;
			if (count != 2 && count != 0)
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
	}
	return 1;
}


//���ʵ��
Xiang::Xiang(string color) :Qizi("��", color) {}
int Xiang::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10)
	{
		cout << "����Խ��,";
		return 0;
	}
	else
	{
		if (start_x <= 4)
		{
			if ((fabs(end_x - start_x) != 2) && (fabs(end_y - start_y) != 2))
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
			else
			{
				if (end_x == start_x + 2)
				{
					if (end_y == start_y + 2)
					{
						if (qp.q[start_x + 1][start_y + 1]->name != "   ")
						{
							cout << "�޷��ƶ�,";
							return 0;
						}
					}
					if (end_y == start_y - 2)
					{
						if (qp.q[start_x + 1][start_y - 1]->name != "   ")
						{
							cout << "�޷��ƶ�,";
							return 0;
						}
					}
				}
				if (end_x == start_x - 2)
				{
					if (end_y == start_y + 2)
					{
						if (qp.q[start_x - 1][start_y + 1]->name != "   ")
						{
							cout << "�޷��ƶ�,";
							return 0;
						}
					}
					if (end_y == start_y - 2)
					{
						if (qp.q[start_x - 1][start_y - 1]->name != "   ")
						{
							cout << "�޷��ƶ�,";
							return 0;
						}
					}
				}
			}
		}
	}
	return 1;
}


//ʿ��ʵ��
Shi::Shi(string color) :Qizi("ʿ", color) {}
int Shi::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (start_x <= 4)
	{
		if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10 || end_x >= 4 || end_y <= 3 || end_y >= 6)
		{
			cout << "����Խ��,";
			return 0;
		}
		else
		{
			if ((fabs(end_x - start_x) != 1) || (fabs(end_y - start_y) != 1))
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
	}
	if (start_x >= 7)
	{
		if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10 || end_x <= 7 || end_y <= 3 || end_y >= 6)
		{
			cout << "����Խ��,";
			return 0;
		}
		else
		{
			if ((fabs(end_x - start_x) != 1) || (fabs(end_y - start_y) != 1))
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
	}
	return 1;
}

//˧��ʵ��
Shuai::Shuai(string color) :Qizi("˧", color) {}
int Shuai::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (qp.q[end_x][end_y]->name == "��")
		return 1;
	else
	{
		if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10 || end_x >= 4 || end_y <= 3 || end_y >= 6)
		{
			cout << "����Խ��,";
			return 0;
		}
		else
		{
			if ((fabs(end_x - start_x) + fabs(end_y - start_y)) != 1)
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
	}
	return 1;
}

//����ʵ��
Jiang::Jiang(string color) :Qizi("��", color) {}
int Jiang::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (qp.q[end_x][end_y]->name == "˧")
		return 1;
	else
	{
		if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10 || end_x <= 7 || end_y <= 3 || end_y >= 6)
		{
			cout << "����Խ��,";
			return 0;
		}
		else
		{
			if ((fabs(end_x - start_x) + fabs(end_y - start_y)) != 1)
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
	}
	return 1;
}

//����ʵ��
Bing::Bing(string color) :Qizi("��", color) {}
int Bing::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (end_x <= 0 || end_x >= 10 || end_y <= 0 || end_y >= 10)
	{
		cout << "����Խ��,";
		return 0;
	}
	else
	{
		if (start_x <= 4 && end_x <= 4)
		{
			if (end_y != start_y && (fabs(end_x - start_x) != 1))
			{
				cout << "�����ƶ�,";
				return 0;
			}
		}
		else
		{
			if ((fabs(end_x - start_x) + fabs(end_y - start_y)) != 1)
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}

	}
	return 1;
}

//���ʵ��
Zu::Zu(string color) :Qizi("��", color) {}
int Zu::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (end_x <= 0 || end_x >= 10 || end_y <= 0 || end_y >= 10)
	{
		cout << "����Խ��,";
		return 0;
	}
	else
	{
		if (end_x <= 4 && start_x >= 7)
		{
			if ((fabs(end_x - start_x) + fabs(end_y - start_y) - 2) != 1)
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
		else
		{
			if ((fabs(end_x - start_x) + fabs(end_y - start_y)) != 1)
			{
				cout << "�޷��ƶ�,";
				return 0;
			}
		}
	}
	return 1;
}

//�����ӵ�ʵ��
Space::Space(string color) :Qizi("   ", color) {}
int Space::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	return 1;
}

//����ʵ��
Qipan::Qipan() :che_red("��"), ma_red("��"), pao_red("��"), xiang_red("��"), shi_red("��"), shuai_red("��"),
bing_red("��"), che_black("��"), ma_black("��"), pao_black("��"), xiang_black("��"),
shi_black("��"), jiang_black("��"), zu_black("��"), space()
{
	int i, j;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 9; j++)
		{
			q[i][j] = &space;
		}
	//��ֵ�췽
	q[1][1] = q[1][9] = &che_red;
	q[1][2] = q[1][8] = &ma_red;
	q[1][3] = q[1][7] = &xiang_red;
	q[1][4] = q[1][6] = &shi_red;
	q[1][5] = &shuai_red;
	q[3][2] = q[3][8] = &pao_red;
	for (i = 1; i <= 10; i = i + 2) q[4][i] = &bing_red;
	//��ֵ�ڷ�
	q[10][1] = q[10][9] = &che_black;
	q[10][2] = q[10][8] = &ma_black;
	q[10][3] = q[10][7] = &xiang_black;
	q[10][4] = q[10][6] = &shi_black;
	q[10][5] = &jiang_black;
	q[8][2] = q[8][8] = &pao_black;
	for (i = 1; i <= 10; i = i + 2) q[7][i] = &zu_black;
}
int Qipan::exist(int x, int y, string color)//����x��y��color��ɫ����
{
	if (q[x][y]->color == color)
		return 1;
	else
		return 0;
}
void Qipan::show()
{
	int i, j;
	for (i = 0; i <= 9; i++)//���ͷ������ 
	{
		if (i == 0)
		{
			cout.width(5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << " ";
		}
		else
		{
			cout.width(5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << i;
		}	
	}
	cout << endl;
	for (i = 1; i <= 10; i++)
	{
		if (i == 5)
		{
			cout << '\n';
			cout.width(5);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
				FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << i ;
		}
		else
		{
			if (i == 6)
			{
				cout << "========================���Ӻ���====================" << endl;
				cout.width(5);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << i;  //���ͷ������
			}
			else
			{
				cout << '\n';
				cout.width(5);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << i;  //���ͷ������			
			}
		}
		for (j = 1; j <= 9; j++)
		{
			cout.width(5);
			if (q[i][j]->color == "��")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << q[i][j]->name;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << q[i][j]->name;
			}			
		}
		cout << endl;
	}
}
