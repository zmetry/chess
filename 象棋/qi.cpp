#include<iostream>
#include<string>
#include"qi.h"
#include<stdlib.h>
#include"windows.h"
using namespace std;

Qizi::Qizi(string name, string color) :name(name), color(color) {}
//车的实现
Che::Che(string color) : Qizi("车", color) {}
int Che::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10)
	{
		cout << "棋子越界,";
		return 0;
	}
	else
	{
		int i;
		//起点、终点不在同一条直线上
		if ((start_x != end_x) && (start_y != end_y))
		{
			cout << "车必须走直线,";
			return 0;
		}
		//横向移动时，中间是否有棋子。
		if (start_x == end_x)
		{
			if (start_y < end_y)
			{
				for (i = start_y + 1; i < end_y; i++)
					if (qp.q[start_x][i]->name != "   ")
					{
						cout << "水平线路上有棋子,";
						return 0;
					}
			}
			else
			{
				for (i = end_y + 1; i < start_y; i++)
					if (qp.q[start_x][i]->name != "   ")
					{
						cout << "水平线路上有棋子,";
						return 0;
					}
			}
		}
		//纵向移动时，中间是否有棋子。
		if (start_y == end_y)
		{
			if (start_x < end_x)
			{
				for (i = start_x + 1; i < end_x; i++)
					if (qp.q[i][start_y]->name != "   ")
					{
						cout << "垂直线路上有棋子,";
						return 0;
					}
			}
			else
			{
				for (i = end_x + 1; i < start_x; i++)
					if (qp.q[i][start_y]->name != "   ")
					{
						cout << "垂直线路上有棋子,";
						return 0;
					}
			}
		}
		return 1;
	}

}
//马的实现
Ma::Ma(string color) :Qizi("马", color) {}
int Ma::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10)
	{
		cout << "棋子越界,";
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
					cout << "无法移动,";
					return 0;
				}
				else
					return 1;
			}
			else
			{
				cout << "无法移动,";
				return 0;
			}
		}
		if (end_y == start_y - 2)
		{
			if (end_x == start_x + 1 || end_x == start_x - 1)
			{
				if (qp.q[start_x][start_y - 1]->name != "   ")
				{
					cout << "无法移动,";
					return 0;
				}
				else
					return 1;
			}
			else
			{
				cout << "无法移动,";
				return 0;
			}
		}
		if (end_x == start_x + 2)
		{
			if (end_y == start_y + 1 || end_y == start_y - 1)
			{
				if (qp.q[start_x + 1][start_y]->name != "   ")
				{
					cout << "无法移动,";
					return 0;
				}
				else
					return 1;
			}
			else
			{
				cout << "无法移动,";
				return 0;
			}
		}
		if (end_x == start_x - 2)
		{
			if (end_y == start_y + 1 || end_y == start_y - 1)
			{
				if (qp.q[start_x - 1][start_y]->name != "   ")
				{
					cout << "无法移动,";
					return 0;
				}
				else
					return 1;
			}
			else
			{
				cout << "无法移动,";
				return 0;
			}
		}
	}
	return 0;
}


//炮的实现
Pao::Pao(string color) :Qizi("炮", color) {}
int Pao::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10)
	{
		cout << "棋子越界,";
		return 0;
	}
	else
	{
		if (end_x != start_x && end_y != start_y)
		{
			cout << "炮必须走直线,";
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
				cout << "无法移动,";
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
				cout << "无法移动,";
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
				cout << "无法移动,";
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
				cout << "无法移动,";
				return 0;
			}
		}
	}
	return 1;
}


//像的实现
Xiang::Xiang(string color) :Qizi("象", color) {}
int Xiang::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10)
	{
		cout << "棋子越界,";
		return 0;
	}
	else
	{
		if (start_x <= 4)
		{
			if ((fabs(end_x - start_x) != 2) && (fabs(end_y - start_y) != 2))
			{
				cout << "无法移动,";
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
							cout << "无法移动,";
							return 0;
						}
					}
					if (end_y == start_y - 2)
					{
						if (qp.q[start_x + 1][start_y - 1]->name != "   ")
						{
							cout << "无法移动,";
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
							cout << "无法移动,";
							return 0;
						}
					}
					if (end_y == start_y - 2)
					{
						if (qp.q[start_x - 1][start_y - 1]->name != "   ")
						{
							cout << "无法移动,";
							return 0;
						}
					}
				}
			}
		}
	}
	return 1;
}


//士的实现
Shi::Shi(string color) :Qizi("士", color) {}
int Shi::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (start_x <= 4)
	{
		if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10 || end_x >= 4 || end_y <= 3 || end_y >= 6)
		{
			cout << "棋子越界,";
			return 0;
		}
		else
		{
			if ((fabs(end_x - start_x) != 1) || (fabs(end_y - start_y) != 1))
			{
				cout << "无法移动,";
				return 0;
			}
		}
	}
	if (start_x >= 7)
	{
		if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10 || end_x <= 7 || end_y <= 3 || end_y >= 6)
		{
			cout << "棋子越界,";
			return 0;
		}
		else
		{
			if ((fabs(end_x - start_x) != 1) || (fabs(end_y - start_y) != 1))
			{
				cout << "无法移动,";
				return 0;
			}
		}
	}
	return 1;
}

//帅的实现
Shuai::Shuai(string color) :Qizi("帅", color) {}
int Shuai::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (qp.q[end_x][end_y]->name == "将")
		return 1;
	else
	{
		if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10 || end_x >= 4 || end_y <= 3 || end_y >= 6)
		{
			cout << "棋子越界,";
			return 0;
		}
		else
		{
			if ((fabs(end_x - start_x) + fabs(end_y - start_y)) != 1)
			{
				cout << "无法移动,";
				return 0;
			}
		}
	}
	return 1;
}

//将的实现
Jiang::Jiang(string color) :Qizi("将", color) {}
int Jiang::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (qp.q[end_x][end_y]->name == "帅")
		return 1;
	else
	{
		if (end_x <= 0 || end_x >= 11 || end_y <= 0 || end_y >= 10 || end_x <= 7 || end_y <= 3 || end_y >= 6)
		{
			cout << "棋子越界,";
			return 0;
		}
		else
		{
			if ((fabs(end_x - start_x) + fabs(end_y - start_y)) != 1)
			{
				cout << "无法移动,";
				return 0;
			}
		}
	}
	return 1;
}

//兵的实现
Bing::Bing(string color) :Qizi("兵", color) {}
int Bing::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (end_x <= 0 || end_x >= 10 || end_y <= 0 || end_y >= 10)
	{
		cout << "棋子越界,";
		return 0;
	}
	else
	{
		if (start_x <= 4 && end_x <= 4)
		{
			if (end_y != start_y && (fabs(end_x - start_x) != 1))
			{
				cout << "不能移动,";
				return 0;
			}
		}
		else
		{
			if ((fabs(end_x - start_x) + fabs(end_y - start_y)) != 1)
			{
				cout << "无法移动,";
				return 0;
			}
		}

	}
	return 1;
}

//卒的实现
Zu::Zu(string color) :Qizi("卒", color) {}
int Zu::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	if (end_x <= 0 || end_x >= 10 || end_y <= 0 || end_y >= 10)
	{
		cout << "棋子越界,";
		return 0;
	}
	else
	{
		if (end_x <= 4 && start_x >= 7)
		{
			if ((fabs(end_x - start_x) + fabs(end_y - start_y) - 2) != 1)
			{
				cout << "无法移动,";
				return 0;
			}
		}
		else
		{
			if ((fabs(end_x - start_x) + fabs(end_y - start_y)) != 1)
			{
				cout << "无法移动,";
				return 0;
			}
		}
	}
	return 1;
}

//空棋子的实现
Space::Space(string color) :Qizi("   ", color) {}
int Space::move(Qipan &qp, int start_x, int start_y, int end_x, int end_y)
{
	return 1;
}

//棋盘实现
Qipan::Qipan() :che_red("红"), ma_red("红"), pao_red("红"), xiang_red("红"), shi_red("红"), shuai_red("红"),
bing_red("红"), che_black("黑"), ma_black("黑"), pao_black("黑"), xiang_black("黑"),
shi_black("黑"), jiang_black("黑"), zu_black("黑"), space()
{
	int i, j;
	for (i = 0; i <= 10; i++)
		for (j = 0; j <= 9; j++)
		{
			q[i][j] = &space;
		}
	//赋值红方
	q[1][1] = q[1][9] = &che_red;
	q[1][2] = q[1][8] = &ma_red;
	q[1][3] = q[1][7] = &xiang_red;
	q[1][4] = q[1][6] = &shi_red;
	q[1][5] = &shuai_red;
	q[3][2] = q[3][8] = &pao_red;
	for (i = 1; i <= 10; i = i + 2) q[4][i] = &bing_red;
	//赋值黑方
	q[10][1] = q[10][9] = &che_black;
	q[10][2] = q[10][8] = &ma_black;
	q[10][3] = q[10][7] = &xiang_black;
	q[10][4] = q[10][6] = &shi_black;
	q[10][5] = &jiang_black;
	q[8][2] = q[8][8] = &pao_black;
	for (i = 1; i <= 10; i = i + 2) q[7][i] = &zu_black;
}
int Qipan::exist(int x, int y, string color)//坐标x、y上color颜色棋子
{
	if (q[x][y]->color == color)
		return 1;
	else
		return 0;
}
void Qipan::show()
{
	int i, j;
	for (i = 0; i <= 9; i++)//输出头行坐标 
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
				cout << "========================楚河汉界====================" << endl;
				cout.width(5);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << i;  //输出头列坐标
			}
			else
			{
				cout << '\n';
				cout.width(5);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
					FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << i;  //输出头列坐标			
			}
		}
		for (j = 1; j <= 9; j++)
		{
			cout.width(5);
			if (q[i][j]->color == "红")
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
