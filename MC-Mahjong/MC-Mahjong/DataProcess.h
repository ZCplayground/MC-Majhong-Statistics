#pragma once
// 单独编译并使用 对面麻数据进行粗处理
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

enum Status { ID, sticks, L1, L22 };

struct Dog {  // 有狗打麻
	string ID;
	int stick; // 点棒
	double score; // 得点
};
using namespace std;

void process1()
{
	// 处理原始的面麻数据文件，处理成适合输入的形式
	// 输入样例：伊利亚50300yuyu22500畅畅23900紫嫣3300
	// 输出样例：伊利亚 50300 yuyu 22500 畅畅 23900 紫嫣 3300

	// special : 紫烟15400畅畅14600L2239200咳血30800 （L22的ID带数字）
	// output:   紫烟 15400 畅畅 14600 L22 39200 咳血 30800 

	ofstream out("out1.txt");

	char c;
	Status status = ID;

	string str;
	stringstream stream;

	while ((c = getchar()) != EOF)
	{
		if (c == '-')
		{
			stream.clear();
			stream.str("");
			stream << c;
			str = stream.str();

			putchar(c);
			out << str;
		}
		if (c == '\n') {
			putchar(c);
			out << endl;
		}
		else if (c == ' ')
			continue; //跳过空白符
		else if (status == ID && (c < 0 || isalpha(c)))
		{
			stream.clear();
			stream.str("");
			stream << c;
			str = stream.str();

			putchar(c);
			out << str;
		}
		else if (status == ID && (c >= '0'&&c <= '9'))
		{
			status = sticks;
			putchar(' ');
			putchar(c);
			out << " ";
			stream.clear();
			stream.str("");
			stream << c;
			str = stream.str();
			out << str;
		}
		else if (status == sticks && (c == 'L'))
		{
			putchar(' ');
			status = L1;
			putchar(c);
			out << " ";
			stream.clear();
			stream.str("");
			stream << c;
			str = stream.str();
			out << str;
		}
		else if (status == sticks && (c >= '0'&&c <= '9'))
		{
			putchar(c);
			stream.clear();
			stream.str("");
			stream << c;
			str = stream.str();
			out << str;
		}
		else if (status == sticks && (c < 0 || isalpha(c)))
		{
			status = ID;
			putchar(' ');
			putchar(c);
			out << " ";
			stream.clear();
			stream.str("");
			stream << c;
			str = stream.str();
			out << str;
		}
		else if (status == ID && (c == 'L'))
		{
			status = L1;
			putchar(c);
			stream.clear();
			stream.str("");
			stream << c;
			str = stream.str();
			out << str;
		}
		else if (status == L1 && (c == '2'))
		{
			status = L22;
			putchar(c);
			stream.clear();
			stream.str("");
			stream << c;
			str = stream.str();
			out << str;
		}
		else if (status == L22 && (c == '2'))
		{
			status = sticks;
			putchar(c);
			putchar(' ');
			stream.clear();
			stream.str("");
			stream << c;
			str = stream.str();
			out << str;
			out << " ";
		}
	}
	out.close();
}

void process2()
{
	// 处理原始面麻数据
	// 输入：只有三个人的名字和点棒 
	// 输入样例： 畅畅 49200 川普 9000 yuyu 15500
	// 输出：第四个人写成 noname ，计算 noname 的点棒
	// 输出样例： 畅畅 49200 川普 9000 yuyu 15500 noname 26300
	ofstream out("out2.txt");
	string ID;

	string input;
	stringstream ss;

	while (1)
	{
		ss.clear();
		ss.str("");

		getline(cin, input);
		ss << input;
		out << input;

		Dog dogs[3];
		for (int i = 0; i < 3; i++)
		{
			ss >> dogs[i].ID;
			ss >> dogs[i].stick;
		}

		int n = 100000 - dogs[0].stick - dogs[1].stick - dogs[2].stick; // 26300 int 型
		out << " noname ";

		string str;
		ss.clear();
		ss.str(""); // 这地方坑了我一小时。。。。重复使用ss一定要clear以及str置空。。。
		ss << n;
		ss >> str;

		cout << str;
		out << str;
		out << endl;

	}
	out.close();
}

void process3()
{   // 处理原始面麻数据
	// 输入：有三个人的名字和点棒 ，第四个人只有名字
	// 输入样例： 妄想 50500  L22 30800 咳血 24000 一身
	// 输出：计算第四人的点棒
	// 输出样例： 妄想 50500  L22 30800 咳血 24000 一身 -5300
	ofstream out("out3.txt");
	string ID;

	string input;
	stringstream ss;

	while (1)
	{
		ss.clear();
		ss.str("");

		getline(cin, input);
		ss << input;
		out << input;

		Dog dogs[4];
		for (int i = 0; i < 3; i++)
		{
			ss >> dogs[i].ID;
			ss >> dogs[i].stick;
		}
		ss >> dogs[3].ID;

		int n = 100000 - dogs[0].stick - dogs[1].stick - dogs[2].stick; // 26300 int 型

		string str;
		ss.clear();
		ss.str(""); // 这地方坑了我一小时。。。。重复使用ss一定要clear以及str置空。。。
		ss << n;
		ss >> str;

		cout << str;
		out << " " << str;
		out << endl;
	}
	out.close();
}

/*
调用本头文件函数的方法：
int main()
{
	//process1();  
	//process2();
	process3();
	

	return 0;

}*/