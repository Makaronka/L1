#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int n = 50;

typedef char TLongInt[n];

struct TLong
{
	TLongInt I;
	TLongInt R;
};

void StrToTLongInt(string str,TLongInt &A)
{
	int temp = 1;

	for (int i = str.length(); str.length() > 1; i -= 2)
	{
		A[temp] = atoi(str.substr(i - 2, 2).c_str());
		str.erase(i - 2, 2);
		temp++;
	}

	if (str.length())
	{
		A[temp] = atoi(str.c_str());
	}
	else temp--;

	A[0] = temp;

	return ;
}

void StrToTLongR(string str, TLongInt &R)
{
	int temp = 1;

	for (int i = 0; i < str.length(); i += 2)
	{
		R[temp] = atoi(str.substr(i, 2).c_str());
		temp++;
	}

	str.erase(0, temp * 2);

	if (str.length())
	{
		R[temp] = atoi(str.c_str());
	}
	else temp--;

	R[0] = temp;

	return;
}

bool Read_TLong(ifstream &fin, TLong& A)
{
	if (fin.is_open())
	{
		string str;
		int temp = 1;

		fin >> str;

		if (str.find('.') == str.npos)
		{
			StrToTLongInt(str, A.I);
			return true;
		}
		else
		{
			StrToTLongInt(str.substr(0,str.find('.')), A.I);
			str.erase(0,str.find('.') + 1);
			StrToTLongR(str.substr(0, str.length()), A.R);
			return true;
		};
	}
	else return false;
}

int main()
{
	setlocale(LC_ALL, "rus");

	string file = "Text.txt";
	ifstream fin(file);
	TLong A;
	TLong B;

	bool flag;

	flag = Read_TLong(fin, A);

	for (int i = 0; i <= A.I[0]; i++)
	{
		cout << (int)A.I[i] << " | ";
	}

	cout << "\n";

	for (int i = 0; i <= A.R[0]; i++)
	{
		cout << (int)A.R[i] << " | ";
	}

	cout << "\n";

	/*
	flag = Read_TLong(fin, B);

	for (int i = 0; i <= B.I[0]; i++)
	{
		cout << (int)B.I[i] << " | ";
	}
	*/

	cout << "\n";

	system("pause");
	return 0;
}