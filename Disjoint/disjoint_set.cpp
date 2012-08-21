#include <iostream>
#include <vector>
using namespace std;

vector<int> mark;


int root(int a)
{
	if (mark[a] < 0) return a;
	else
	{
		int rtn = root(mark[a]);
		mark[a] = rtn;

		return rtn;
	}
}

void merge(int a, int b)
{
	a = root(a);
	b = root(b);
	if (a == b) return;
	if (mark[a] < mark[b])
	{
		mark[a] += mark[b];
		mark[b] = a;
	} else
	{
		mark[b] += mark[a];
		mark[a] = b;
	}
}

int main()
{
	int N, M;

	cin >> N >> M;
	mark.resize(N + 1, -1);
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	for (int i = 1; i <= N; i++)
		cout << mark[i] << endl;
}
