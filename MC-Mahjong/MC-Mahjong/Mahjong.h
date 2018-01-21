#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<iomanip>

#define MAXLEN 100  // 一行输入的最大长度
#define MAXGAME 100 // 统计一人数据的最大比赛数量

using namespace std;

struct Dog {  // 有狗打麻
	string ID;
	int stick; // 点棒
	double score; // 得点
	friend ostream & operator<<(ostream & os, const Dog d);
};

ostream & operator<<(ostream & os, const Dog d) // 用于输出单只狗，输出格式：ID(score) 
{
	cout.setf(ios::fixed);
	if (d.score > 0)
		os << d.ID << "(+" << fixed << setprecision(1) << d.score << ") "; // 若 score 为正，输出 + 号

	else
		os << d.ID << "(" << fixed << setprecision(1) << d.score << ") ";

	return os;
}


bool cmp(Dog d1, Dog d2) // 按照点棒从大到小排列，用于 sort 函数
{
	return d1.stick > d2.stick; 
}

class Mahjong { // Mahjong 类，一个对象指代一局比赛

private:
	Dog dogs[4];
	static int num; 

public:
	Mahjong() {};
	Mahjong(Dog a[]);
	void WriteResult();
	void Print();
	friend ostream & operator<<(ostream & os, const Mahjong &e);

	void Personal_Game_Statistics();
	void Personal_Technical_Statistics(string &ID);
}; 

int Mahjong::num = 0;// 比赛编号

Mahjong::Mahjong(Dog a[]) // 构造函数：排序，计算得点。
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
	double sum = 0.0;
	for (int i = 0; i < 4; i++)
		sum += dogs[i].score;

	if (sum != 0.0)
		dogs[0].score = 0 - (dogs[1].score + dogs[2].score + dogs[3].score);
}

ostream & operator<<(ostream & os, const Mahjong &e)  //输出所有狗
{
	cout.setf(ios::fixed);
	for (int i = 0; i < 4; i++)
		if (e.dogs[i].score > 0)
			os << i + 1 << "." << e.dogs[i].ID << "(+" << fixed << setprecision(1) << e.dogs[i].score << ") ";
		else
			os << i + 1 << "." << e.dogs[i].ID << "(" << fixed << setprecision(1) << e.dogs[i].score << ") ";

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

void Mahjong::Personal_Game_Statistics()
{
	// 4. 遍历一局麻将中的四个人，
	// 在 ID.txt 后追加比赛信息  
	// 输出格式样例： 4位 changc(-40.0) Haruhi(+44.0) 學習個煎包麻將(-13.0) 小手冰凉(+9.0)
	string path;
	fstream f;

	for (int i = 0; i < 4; i++)
	{
		path.clear(); 
		path += dogs[i].ID;
		path += ".txt";
		f.open(path, ios::app);

		f << i + 1 << "位 ";
		f << dogs[i]; //先输出自己的位次和ID以及得点。剩余再依次从高到低输出

		for (int j = 0; j < 4; j++)
			if (j == i) continue;
			else
				f << dogs[j];

		f << endl;
		f.close();
	}
	
}

void Mahjong::Personal_Technical_Statistics(string &ID)
{
	// 5. 根据 ID.txt 统计 一二三四被飞位率，top，last，连对率，平均顺位，平均得点。（等等）

	string path = ID;
	path += ".txt";

	fstream f;
	f.open(path, ios::in);
	
	char one_line[MAXLEN];
	int rank[MAXGAME];

	int top = 0, last = 0, liandui = 0;
	double toprate = 0.0, lastrate = 0.0, lianduirate = 0.0;
	//double totalscore = 0.0, average = 0.0; 平均得点 to be done

	int i;
	for (i = 0; f.getline(one_line, MAXLEN); i++) //不断获取一行输入
	{
		 // 每行的第一个字节是顺位
		rank[i]= one_line[0] - '0';
		memset(one_line, 0, sizeof(one_line));
	}
	int len = i;

	for (i = 0; i < len; i++)
	{
		if (rank[i] == 1) {
			liandui++; top++;
		}
		else if (rank[i] == 2) {
			liandui++;
		}
		else if (rank[i] == 4) {
			last++; 
		}
	}

	toprate = (double)top / len;
	lianduirate = (double)liandui / len;
	lastrate = (double)last / len;

	cout.setf(ios::fixed);
	cout << "top 率: " << fixed << setprecision(3) << toprate << " ";
	cout << "连对率：" << fixed << setprecision(3) << lianduirate << " ";
	cout << "末位率：" << fixed << setprecision(3) << lastrate << " ";
	
	f.close();
}