#include<iostream>
#include<string>
#include<sstream>

#include"Mahjong.h"
#include"statistics.h"

int main()
{
	// ���� 29000  yuyu 54300  ��ʼ -3000  L22 19700
	string input;
	stringstream ss;
	while (1) {
		ss.clear();

		getline(cin, input);
		ss << input; // 1. ��ȡһ������

		Dog dogs[4];
		for (int i = 0; i < 4; i++)
		{
			ss >> dogs[i].ID;
			ss >> dogs[i].stick;
		}
		
		Mahjong g = Mahjong(dogs);  // 2. ���򣬼���õ�ȣ�C++�����죩��

		g.Print(); // 3. ���һ��������һ��
		g.WriteResult();

		// 4. ���������ĸ��ˣ��Ƿ���Dogs.txt��������Ա�б��

		// �����ڣ��� Dogs.txt ��׷�Ӵ��� ID ��ִ����һ��
		// �� ID.txt ��׷�ӱ�����Ϣ
		
		// 5. ���� ID.txt ͳ�� һ������λ�ʣ�top��last�������ʣ�ƽ��˳λ��ƽ���õ㡣���ȵȣ�
	}
	return 0;
}

/*
����1��
main�����У� 

Dog dogs[4];
dogs[0].ID = "yuyu";
dogs[3].stick = 54300;
dogs[1].ID = "changc";
dogs[2].stick = 29000;
dogs[2].ID = "l22";
dogs[1].stick = 19700;
dogs[3].ID = "chushi";
dogs[0].stick = -3000;

���� ���� Mahjong ���캯�� ������ ��score���㡣 ��ɡ�
*/

/*
��������2 ���ڲ��� stringstream�� ��ɡ�

// ����̨���룺 yuyu 54300 changc 29000 122 19700 chushi -3000 

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