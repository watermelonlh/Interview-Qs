#include <iostream>
#include <string>
using namespace std;

void strReverse(string &S)
{
	int len = S.size();
	for (int i = 0; i < len / 2; i++)
	{
		swap(S[i], S[len - 1 - i]);
	}
}

int main()
{
	string S;
	cin >> S;
	strReverse(S);
	cout << S;
}	
