#include<iostream>
#include<string>
#include<stdlib.h>
#include"qi.h"
using namespace std;

int main()
{
	int game_over = 0;
	Qipan qipan;
	int start_x, start_y, end_x, end_y;
	qipan.show();
	string color;
	int step = 1;
	string colors[2] = { "黑","红" };
	while (1)
	{
		color = colors[step % 2];
		cout << "请输入第" << step << "步需要移动" << color << "色棋子的原始位置坐标（x和y）：" << endl;
		cin >> start_x >> start_y;
		if (!qipan.exist(start_x, start_y, color))
		{
			cout << "坐标（" << start_x << "，" << start_y << "）没有" << color << "色棋子,本步重走" << endl;
			continue;
		}
		cout << "请输入第" << step << "步需要移动" << color << "色棋子的目的位置坐标（x和y）：" << endl;
		cin >> end_x >> end_y;
		if (qipan.exist(end_x, end_y, color))
		{
			cout << "坐标（" << end_x << "，" << end_y << "） 有" << color << "色棋子,本步重走" << endl;
			continue;
		}
		if (!qipan.q[start_x][start_y]->move(qipan, start_x, start_y, end_x, end_y))
		{
			cout << "移动规则不符，本步重走" << endl;
			continue;
		}
		if (qipan.q[end_x][end_y]->name == "帅")
			game_over = 1;
		if (qipan.q[end_x][end_y]->name == "将")
			game_over = 2;
		//移动
		qipan.q[end_x][end_y] = qipan.q[start_x][start_y];
		qipan.q[start_x][start_y] = &qipan.space;
		//刷新棋盘
		system("cls");
		qipan.show();
		step++;
		if (game_over == 1)
		{
			cout << "黑方胜利" << endl;
			system("pause");
			return 0;
		}
		if (game_over == 2)
		{
			cout << "红方胜利" << endl;
			system("pause");
			return 0;
		}
	}
	return 0;
}