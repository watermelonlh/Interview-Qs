#include <iostream>
using namespace std;

int top[4];
int tot = 0;

void insert(int x)
{
	int i = 0;
	while (i < tot)
	{
		if (x < top[i])
		{
			i++;
		} else
		{
			if (tot < 4) tot++;
			for (int k = tot - 1; k > i; k--)
				top[k] = top[k - 1];
			top[i] = x;
			return;
		}
	}
	if (tot < 4) top[tot++] = x;
}


int main()
{
	int N;
	int x;
	cin >> N;

	while (N--)
	{
		cin >> x;
		insert(x);
	}

	for (int i = 0; i < tot; i++)
	{
		cout << top[i] << endl;
	}

}
