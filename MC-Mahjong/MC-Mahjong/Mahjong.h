#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<iomanip>

using namespace std;

int num = 0; // 比赛编号

struct Dog {  // 有狗打麻
	string ID;
	int stick; // 点棒
	double score; // 得点
};

bool cmp(Dog d1, Dog d2) // 按照点棒从大到小排列
{
	return d1.stick > d2.stick; 
}

class Mahjong {

private:
	Dog dogs[4];
	
public:
	Mahjong() {};
	Mahjong(Dog a[]);
	void WriteResult();
	void Print();
	friend ostream & operator<<(ostream & os, const Mahjong &e);
}; 

Mahjong::Mahjong(Dog a[])
{
	for (int i = 0; i < 4; i++)
		dogs[i] = a[i];

	sort(dogs, dogs + 4, cmp);  // 按照点棒从大到小排列
	
	// 分数计算方法：（当前点数－返点）÷1000+顺位马+头名赏
	// 顺位马也叫做顺位调整分，通常以X－Y代表。例如8－4，即第一名+8，第二名+4，第三名-4，第四名-8。
	// 头名赏计算方法：（返点－原点）÷1000×人数。只有第一名可以获得头名赏。 20
	dogs[0].score = ((double)dogs[0].stick - 30000) / 1000 + 8 + 20;
	dogs[1].score = ((double)dogs[1].stick - 30000) / 1000 + 4;
	dogs[2].score = ((double)dogs[2].stick - 30000) / 1000 - 4;
	dogs[3].score = ((double)dogs[3].stick - 30000) / 1000 - 8;

	// 计算完成后，如果各家分数相加之和不为0，则调整第一名的分数，使各家分数相加之和等于0。 
}

ostream & operator<<(ostream & os, const Mahjong &e)  //输出本场比赛，一行
{
	cout.setf(ios::fixed);
	for (int i = 0; i < 4; i++)
		os << i + 1 << "." << e.dogs[i].ID << "(" << fixed << setprecision(1)<<e.dogs[i].score << ") ";
	return os;
}

void Mahjong::Print() // 标准输出
{
	cout << *this << endl;
}

void Mahjong::WriteResult() // 写入一场比赛
{
	fstream f;
	f.open("data.txt", ios::app);
	num++;
	f << "No." << num <<": " << *this << endl;
}