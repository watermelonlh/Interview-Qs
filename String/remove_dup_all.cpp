#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void removeAllDup(string &S)
{
	bool mark[256];
	memset(mark, 0, sizeof(mark));
	int l = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (!mark[S[i]])
		{
			mark[S[i]] = true;
			S[l++] = S[i];
		}
	}
	S.erase(l);
}

int main()
{
	string S;
	cin >> S;
	removeAllDup(S);
	cout << S;
}
