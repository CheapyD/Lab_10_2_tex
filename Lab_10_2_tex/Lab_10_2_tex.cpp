#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

int MinLength(char* fname);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char fname[] = "t.txt";
	int Length;
	Length = MinLength(fname);
	cout << "Довжина найкоротшого слова: " << Length << endl;

	system("pause");
	return 0;
}

int MinLength(char* fname)
{
	ifstream fin(fname);
	string s;
	int k = 0;
	size_t len = 0,
		min = 0;
	size_t start = 0,
		finish;
	while (getline(fin, s))
	{
		while ((start = s.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", start)) != -1)
		{
			finish = s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", start + 1);
			if (finish == -1)
				finish = s.length();
			len = finish - start;
			if (k == 0)
				min = len;
			k++;
			if (len < min)
				min = len;
			start = finish + 1;
		}
	}
	return min;
}