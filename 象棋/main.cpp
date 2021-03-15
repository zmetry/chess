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
	string colors[2] = { "��","��" };
	while (1)
	{
		color = colors[step % 2];
		cout << "�������" << step << "����Ҫ�ƶ�" << color << "ɫ���ӵ�ԭʼλ�����꣨x��y����" << endl;
		cin >> start_x >> start_y;
		if (!qipan.exist(start_x, start_y, color))
		{
			cout << "���꣨" << start_x << "��" << start_y << "��û��" << color << "ɫ����,��������" << endl;
			continue;
		}
		cout << "�������" << step << "����Ҫ�ƶ�" << color << "ɫ���ӵ�Ŀ��λ�����꣨x��y����" << endl;
		cin >> end_x >> end_y;
		if (qipan.exist(end_x, end_y, color))
		{
			cout << "���꣨" << end_x << "��" << end_y << "�� ��" << color << "ɫ����,��������" << endl;
			continue;
		}
		if (!qipan.q[start_x][start_y]->move(qipan, start_x, start_y, end_x, end_y))
		{
			cout << "�ƶ����򲻷�����������" << endl;
			continue;
		}
		if (qipan.q[end_x][end_y]->name == "˧")
			game_over = 1;
		if (qipan.q[end_x][end_y]->name == "��")
			game_over = 2;
		//�ƶ�
		qipan.q[end_x][end_y] = qipan.q[start_x][start_y];
		qipan.q[start_x][start_y] = &qipan.space;
		//ˢ������
		system("cls");
		qipan.show();
		step++;
		if (game_over == 1)
		{
			cout << "�ڷ�ʤ��" << endl;
			system("pause");
			return 0;
		}
		if (game_over == 2)
		{
			cout << "�췽ʤ��" << endl;
			system("pause");
			return 0;
		}
	}
	return 0;
}