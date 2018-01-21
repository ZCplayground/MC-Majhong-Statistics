#include<iostream>
#include<string>
#include<sstream>

#include"Mahjong.h"
#include"statistics.h"

int main()
{
	// 畅畅 29000  yuyu 54300  初始 -3000  L22 19700
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

		// 4. 遍历查找四个人，是否在Dogs.txt（你社人员列表里）

		// 若不在，在 Dogs.txt 中追加此人 ID 并执行下一步
		// 在 ID.txt 后追加比赛信息
		
		// 5. 根据 ID.txt 统计 一二三四位率，top，last，连对率，平均顺位，平均得点。（等等）
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