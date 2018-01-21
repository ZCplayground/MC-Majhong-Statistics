#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
// ����ԭʼ�����������ļ���������ʺ��������ʽ
// ����������������50300yuyu22500����23900����3300
// ��������������� 50300 yuyu 22500 ���� 23900 ���� 3300

// special : ����15400����14600L2239200��Ѫ30800 ��L22��ID�����֣�
// output:   ���� 15400 ���� 14600 L22 39200 ��Ѫ 30800 

enum Status { ID, sticks, L1, L22 };

using namespace std;

int main()
{ 
	ofstream out("out.txt"); 

	char c;
	Status status = ID; 
	
	while ((c = getchar()) != EOF)
	{
		if (c == '\n') {
			putchar(c);
			out << endl;
		}
		else if (c == ' ')
			continue; //�����հ׷�
		else if (status == ID && (c < 0 || isalpha(c)))
		{
			string str;
			stringstream stream;
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
			string str;
			stringstream stream;
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
			string str;
			stringstream stream;
			stream << c;
			str = stream.str();
			out << str;
		}
		else if (status == sticks && (c >= '0'&&c <= '9'))
		{
			putchar(c);
			string str;
			stringstream stream;
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
			string str;
			stringstream stream;
			stream << c;
			str = stream.str();
			out << str;
		}
		else if (status == ID && (c == 'L'))
		{
			status = L1;
			putchar(c);
			string str;
			stringstream stream;
			stream << c;
			str = stream.str();
			out << str;
		}
		else if (status == L1 && (c == '2'))
		{
			status = L22;
			putchar(c);
			string str;
			stringstream stream;
			stream << c;
			str = stream.str();
			out << str;
		}
		else if (status == L22 && (c == '2'))
		{
			status = sticks;
			putchar(c);
			putchar(' ');
			string str;
			stringstream stream;
			stream << c;
			str = stream.str();
			out << str;
			out << " ";
		}
	}
	out.close();
	return 0;
}