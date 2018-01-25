#pragma once
// �������벢ʹ�� ���������ݽ��дִ���
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

enum Status { ID, sticks, L1, L22 };

struct Dog {  // �й�����
	string ID;
	int stick; // ���
	double score; // �õ�
};
using namespace std;

void process1()
{
	// ����ԭʼ�����������ļ���������ʺ��������ʽ
	// ����������������50300yuyu22500����23900����3300
	// ��������������� 50300 yuyu 22500 ���� 23900 ���� 3300

	// special : ����15400����14600L2239200��Ѫ30800 ��L22��ID�����֣�
	// output:   ���� 15400 ���� 14600 L22 39200 ��Ѫ 30800 

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
			continue; //�����հ׷�
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
	// ����ԭʼ��������
	// ���룺ֻ�������˵����ֺ͵�� 
	// ���������� ���� 49200 ���� 9000 yuyu 15500
	// ��������ĸ���д�� noname ������ noname �ĵ��
	// ��������� ���� 49200 ���� 9000 yuyu 15500 noname 26300
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

		int n = 100000 - dogs[0].stick - dogs[1].stick - dogs[2].stick; // 26300 int ��
		out << " noname ";

		string str;
		ss.clear();
		ss.str(""); // ��ط�������һСʱ���������ظ�ʹ��ssһ��Ҫclear�Լ�str�ÿա�����
		ss << n;
		ss >> str;

		cout << str;
		out << str;
		out << endl;

	}
	out.close();
}

void process3()
{   // ����ԭʼ��������
	// ���룺�������˵����ֺ͵�� �����ĸ���ֻ������
	// ���������� ���� 50500  L22 30800 ��Ѫ 24000 һ��
	// �������������˵ĵ��
	// ��������� ���� 50500  L22 30800 ��Ѫ 24000 һ�� -5300
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

		int n = 100000 - dogs[0].stick - dogs[1].stick - dogs[2].stick; // 26300 int ��

		string str;
		ss.clear();
		ss.str(""); // ��ط�������һСʱ���������ظ�ʹ��ssһ��Ҫclear�Լ�str�ÿա�����
		ss << n;
		ss >> str;

		cout << str;
		out << " " << str;
		out << endl;
	}
	out.close();
}

/*
���ñ�ͷ�ļ������ķ�����
int main()
{
	//process1();  
	//process2();
	process3();
	

	return 0;

}*/