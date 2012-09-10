#include <iostream>
#include <cstring>
using namespace std;

int lc[100], rc[100], pa[100];
int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> lc[i] >> rc[i] >> pa[i];

	int head = 0, tail = 1;
	int list[200];
	list[0] = 1;
	bool mark[100];
	memset(mark, 0, sizeof(mark));
	mark[0] = true;
	int inOrder[100];
	inOrder[0] = 1;
	int tot = 1;
	while (head < tail)
	{
		int now = list[head++];

		if (lc[now] > 0 && !mark[lc[now]])
		{
			mark[lc[now]] = true;
			inOrder[tot++] = lc[now];
			list[tail++] = lc[now];
		} else if (rc[now] > 0 && !mark[rc[now]])
		{
			mark[rc[now]] = true;
			inOrder[tot++] = rc[now];
			list[tail++] = rc[now];
		} else if (pa[now] > 0)
		{
			list[tail++] = pa[now];
		}
	}
	for (int i = 0; i < tot; i++)
		cout << inOrder[i] << endl;
}
