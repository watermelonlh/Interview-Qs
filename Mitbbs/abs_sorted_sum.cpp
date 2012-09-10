#include <iostream>
using namespace std;

int N;
int num[100];

void moveL(int &L)
{
	if (num[L] < 0)
	{
		L--;
		while (L >= 0 && num[L] >= 0) L--;
		if (L == -1) 
		{
			L = 0;
			while (L < N && num[L] < 0) L++;
		}
	} else
	{
		L++;
		while (L < N && num[L] < 0) L++;
	}
}

void moveR(int &R)
{
	if (num[R] >= 0)
	{
		R--;
		while (R >= 0 && num[R] < 0) R--;
		if (R == -1)
		{
			R = 0;
			while (R < N && num[R] >= 0) R++;
		}
	} else
	{
		R++;
		while (R < N && num[R] >= 0) R++;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	int target;
	cin >> target;

	int L = N - 1;
	while (L >= 0 && num[L] >= 0) L--;
	if (L == -1) L = 0;
	int R = N - 1;
	while (R >= 0 && num[R] < 0) R--;
	if (R == -1) R = 0;
	while (L != R)
	{
		while (L != R && num[L] + num[R] < target) moveL(L);
		while (L != R && num[L] + num[R] > target) moveR(R);
		if (L != R && num[L] + num[R] == target) 
		{
			cout << num[L] << ' ' << num[R] << endl;
			moveL(L);
			if (L != R) moveR(R);
		}
	}

}
