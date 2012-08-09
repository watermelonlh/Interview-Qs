#include <iostream>
#include <cstring>
using namespace std;

void remove_dup(char S[])
{
	int l = 0;
	int len = strlen(S);
	for (int i = 1; i < len; i++)
	{
		if (S[i] == S[l]) 
		{
			
		} else
		{
			l++;
			S[l] = S[i];
		}
	}
	S[l + 1] = '\0';
}

int main()
{
	char S[100];
	cin >> S;
	remove_dup(S);
	cout << S;
}
