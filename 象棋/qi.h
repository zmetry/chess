#pragma once
#include<iostream>
#include<string>
using namespace std;
class Qipan;
class Qizi {
public:
	string  name;
	string color;
	Qizi(string name, string color);
	//返回1代表移动合法；返回0代表移动不合法。
	virtual int move(Qipan &qp, int start_x, int start_y, int end_x, int end_y) = 0;
};
class Che :public Qizi {
public:
	Che(string color);
	int move(Qipan &qp, int start_x, int start_y, int end_x, int end_y);
};
class Ma :public Qizi {
public:
	Ma(string color);
	int move(Qipan &qp, int start_x, int start_y, int end_x, int end_y);
};
class Pao :public Qizi {
public:
	Pao(string color);
	int move(Qipan &qp, int start_x, int start_y, int end_x, int end_y);
};
class Xiang :public Qizi {
public:
	Xiang(string color);
	int move(Qipan &qp, int start_x, int start_y, int end_x, int end_y);
};
class Shi :public Qizi {
public:
	Shi(string color);
	int move(Qipan &qp, int start_x, int start_y, int end_x, int end_y);
};
class Shuai :public Qizi {
public:
	Shuai(string color = "B");
	int move(Qipan &qp, int start_x, int start_y, int end_x, int end_y);
};
class Jiang :public Qizi {
public:
	Jiang(string color = "B");
	int move(Qipan &qp, int start_x, int start_y, int end_x, int end_y);
};
class Bing :public Qizi {
public:
	Bing(string color = "B");
	int move(Qipan &qp, int start_x, int start_y, int end_x, int end_y);
};
class Zu :public Qizi {
public:
	Zu(string color = "B");
	int move(Qipan &qp, int start_x, int start_y, int end_x, int end_y);
};
class Space :public Qizi {
public:
	Space(string color = "  ");
	int move(Qipan &qp, int start_x, int start_y, int end_x, int end_y);
};
class Qipan {
public:
	//定义棋盘
	Qizi *q[11][10];
	//定义棋子
	Che che_red; Ma ma_red; Pao pao_red; Xiang xiang_red; Shi shi_red; Shuai shuai_red; Bing bing_red;
	Che che_black; Ma ma_black; Pao pao_black; Xiang xiang_black; Shi shi_black; Jiang jiang_black; Zu zu_black;
	Space space;
	Qipan();
	int exist(int x, int y, string color);//坐标x、y上color颜色棋子
	void show();
};