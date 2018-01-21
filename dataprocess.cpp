#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
// 处理原始的面麻数据文件，处理成适合输入的形式
// 输入样例：伊利亚50300yuyu22500畅畅23900紫嫣3300
// 输出样例：伊利亚 50300 yuyu 22500 畅畅 23900 紫嫣 3300

// special : 紫烟15400畅畅14600L2239200咳血30800 （L22的ID带数字）
// output:   紫烟 15400 畅畅 14600 L22 39200 咳血 30800 

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
			continue; //跳过空白符
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