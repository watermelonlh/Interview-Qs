#include <iostream>
#include <string>
using namespace std;

void reverse(string &S, int left, int right)
{
	int len = right - left + 1;
	for (int i = 0; i < len / 2; i++)
	{
		swap(S[left + i], S[right - i]);
	}
}

void reverse_sentence(string &S)
{
	int left = 0;
	int len = S.size();
	for (int i = 0; i < len; i++)
	{
		if (S[i] == ' ')
		{
			reverse(S, left, i - 1);
			left = i + 1;
		}
	}
	if (left < len)
	{
		reverse(S, left, len - 1);
	}
	reverse(S, 0, len - 1);
}

int main()
{
	string S;
	getline(cin, S);
	reverse_sentence(S);
	cout << S;
}

