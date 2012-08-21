#include <iostream>
#include <vector>
using namespace std;


struct node
{
	int v;
	int w;

	node(int _v, int _w) : v(_v), w(_w) {}
};

const int MAXN = 1000;
vector<node> edge[MAXN];
vector<int> dist;
vector<bool> mark;
int N, M;

void prim(int K)
{
	dist.resize(N + 1, -1);
	mark.resize(N + 1, false);
	dist[K] = 0;

	while (true)
	{
		int min = -1;
		int minV = 0;
		for (int i = 1; i <= N; i++)
		{
			if (!mark[i] && (min == -1 || dist[i] < min))
			{
				min = dist[i];
				minV = i;
			}
		}
		if (minV == 0) break;
		mark[minV] = true;
		for (int i = 0; i < edge[minV].size(); i++)
		{
			int v = edge[minV][i].v;
			int w = edge[minV][i].w;
			if (dist[v] == -1 || dist[v] > w)
			{
				dist[v] = w;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
		edge[i].clear();
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edge[a].push_back(node(b, w));
		edge[b].push_back(node(a, w));
	}

	int K, ans = 0;
	prim(1);
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == -1) 
		{
			ans = -1;
			break;
		} else ans += dist[i];
	}
	
	cout << ans << endl;
}

