#include<iostream>
#include<string>
#include<sstream>
#include"Mahjong.h"
int main()
{
	// 样例：畅畅 29000  yuyu 54300  初始 -3000  L22 19700
	string input;
	stringstream ss;
	while (1) {
		// TODO：封装成两个函数：1. 输入比赛 2. 某位选手的技术统计

		ss.clear();

		getline(cin, input);
		ss << input; // 1. 获取一行输入

		Dog dogs[4];
		for (int i = 0; i < 4; i++)
		{
			ss >> dogs[i].ID;
			ss >> dogs[i].stick;
		}

		Mahjong g = Mahjong(dogs);  // 2. 排序，计算得点等（C++对象构造）。

		g.Print(); // 3. 输出一场比赛，一行
		g.WriteResult();

		// 4. 遍历查找四个人，在 ID.txt 后追加比赛信息
		g.Personal_Game_Statistics();  
		
		
		// 以上是输入比赛/*~~~~~~~~~~~~~~~~~~~ 分割线 ~~~~~~~~~~~~~~~~~~~~~~~~~*/// 以下是对特定选手的技术统计
		
		// 5. 根据 ID.txt 统计 一二三四位率，top，last，连对率，平均顺位，平均得点。（等等）
		string name;
		cin >> name;
		// TODO: 保存所有选手ID 的文件，自动统计
		Mahjong g;
		g.Personal_Technical_Statistics(name);
	}
	return 0;
}

/*
测试1：
main函数中： 

Dog dogs[4];
dogs[0].ID = "yuyu";
dogs[3].stick = 54300;
dogs[1].ID = "changc";
dogs[2].stick = 29000;
dogs[2].ID = "l22";
dogs[1].stick = 19700;
dogs[3].ID = "chushi";
dogs[0].stick = -3000;

用于 测试 Mahjong 构造函数 排序功能 ，score计算。 完成。
*/

/*
测试用例2 用于测试 stringstream。 完成。

// 控制台输入： yuyu 54300 changc 29000 122 19700 chushi -3000 

	string input;
	stringstream ss;
	
	getline(cin,input);
	ss << input;

	Dog dogs[4];
	for (int i = 0; i < 4; i++)
	{
		ss >> dogs[i].ID;
		ss >> dogs[i].stick;
	}

	Mahjong g = Mahjong(dogs);
	g.display();
*/

/*
用于测试输出到文件（一行），完成

string input;
stringstream ss;
while (1) {
ss.clear();

getline(cin, input);
ss << input; // 1. 获取一行输入

Dog dogs[4];
for (int i = 0; i < 4; i++)
{
ss >> dogs[i].ID;
ss >> dogs[i].stick;
}

Mahjong g = Mahjong(dogs);  // 2. 排序，计算得点等（C++对象构造）。

g.Print(); // 3. 输出一场比赛，一行
g.WriteResult();

*/

