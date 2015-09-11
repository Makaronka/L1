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
	while (str[0] == '0' && str.length() > 1)
	{
		str.erase(0, 1);
	}

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
	while (str[str.length()-1] == '0' && str.length() > 1)
	{
		str.erase(str.length() - 1, 1);
	}

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
			A.R[0] = 0;
			return true;
		}
		else
		{
			StrToTLongInt(str.substr(0,str.find('.')), A.I);
			str.erase(0,str.find('.') + 1);
			StrToTLongR(str.substr(0, str.length()), A.R);
			return true;
		}
	}
	else return false;
}


void Write_TLong(ostream &fout, TLong A)
{
	fout << (int)A.I[A.I[0]];

	for (int i = A.I[0] - 1; i > 0; i--)
	{
		if (A.I[i] < 10)
		{
			fout << "0";
		}

		fout << (int)A.I[i];
	}

	if (A.R[0])
	{
		fout << ".";
		for (int i = 1; i < A.R[0]; i++)
		{
			if (A.R[i] < 10)
			{
				fout << "0";
			}

			fout << (int)A.R[i];  
		}
		fout << (int)A.R[A.R[0]];
	}

	fout << endl;
	return;
}

bool Equal_TLong(TLong A, TLong B)
{
	if (A.I[0] != B.I[0] || A.R[0] != B.R[0])
	{
		return false;
	}
	for (int i = 1; i <= A.I[0]; i++)
	{
		if (A.I[i] != B.I[i])
		{
			return false;
		}
	}
	for (int i = 1; i <= A.R[0]; i++)
	{
		if (A.R[i] != B.R[i])
		{
			return false;
		}
	}

	return true;
}

bool Less_TLong(TLong A, TLong B)
{
	if (B.I[0] > A.I[0])
	{
		return false;
	}

	if (!(Equal_TLong(A, B)) && (A.I[0] == B.I[0]))
	{
		for (int i = A.I[0]; i > 0 ; i--)
		{
			if (A.I[i] < B.I[i])
			{
				return false;
			}
		}
		if (A.R[0] < B.R[0])
		{
			for (int i = 1; i <= A.R[0]; i++)
			{
				if (A.R[i] < B.R[i])
				{
					return false;
				}
			}
			return false;
		}
		else
		{
			for (int i = 1; i <= B.R[0]; i++)
			{
				if (A.R[i] < B.R[i])
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "rus");

	string file = "Text.txt";
	string output = "Output.txt";
	ifstream fin(file);
	ofstream fout(output);
	TLong A;
	TLong B;

	bool flag;

	flag = Read_TLong(fin, A);
	flag = Read_TLong(fin, B);

	Write_TLong(fout, A);
	Write_TLong(fout, B);

	Write_TLong(cout, A);
	Write_TLong(cout, B);

	system("pause");
	return 0;
}