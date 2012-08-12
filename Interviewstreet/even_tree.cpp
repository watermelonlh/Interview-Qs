#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int N, M;
bool G[101][101];
bool mark[101];
int count[101];

void getCount(int fa, int now)
{
	mark[now] = true;
	count[now] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (i == fa) continue;
		if (G[now][i]) 
		{
			getCount(now, i);
			count[now] += count[i];
		}
	}
}

int cut(int fa, int now)
{
	int res = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i == fa) continue;
		if (G[now][i])
		{
			res += !(count[i] & 1) + cut(now, i);
		}
	}
	return res;
}

int main()
{
	cin >> N >> M;
	int a, b;
	while (M--)
	{
		cin >> a >> b;
		G[a][b] = G[b][a] = true;
	}



	memset(mark, 0, sizeof(mark));
	for (int i = 1; i <= N; i++)
	{
		if (mark[i]) continue;
		getCount(0, i);	
		mark[i] = false;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (mark[i]) continue;
		ans += cut(0, i);
	}
	cout << ans << endl;
}
