#include <iostream>
#include <string>
using namespace std;

string S, T;
int next[1000];
int ext[1000];

void GetNext(string &T)
{
	int l = T.size();
	int farPosition = 0, zeroPosition = 0;
	next[0] = 0;
	for (int i = 1; i < l; i++)
	{
		if (farPosition < i || next[i - zeroPosition] + i - 1 >= farPosition)
		{
			if (farPosition < i) farPosition = i - 1;
			int j = farPosition - i;
			while (farPosition < l - 1 && T[j + 1] == T[farPosition + 1])
			{
				farPosition++;
				j++;
			}
			next[i] = farPosition - i + 1;
			zeroPosition = i;
		} else next[i] = next[i - zeroPosition];
	}
	for (int i = 0; i < l; i++)
	{
		cout << T[i] << " next= " << next[i] << endl;
	}
}

void GetExt(string &S, string &T)
{
	int ls = S.size(), lt = T.size();
	int farPosition = -1, zeroPosition = -1;
	for (int i = 0; i < ls; i++)
	{
		if (farPosition < i || next[i - zeroPosition] + i - 1 >= farPosition)
		{
			if (farPosition < i) farPosition = i - 1;
			int j = farPosition - i;
			while (farPosition < ls - 1 && j < lt - 1 && T[j + 1] == S[farPosition + 1])
			{
				farPosition++;
				j++;
			}
			ext[i] = farPosition - i + 1;
			zeroPosition = i;
		} else ext[i] = next[i - zeroPosition];
	}

	for (int i = 0; i < ls; i++)
	{
		cout << S[i] << " ext= " << ext[i] << endl;
	}
}

int main()
{
	cin >> S >> T;
	GetNext(T);
	GetExt(S, T);
}
