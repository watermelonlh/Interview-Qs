#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int> > G;

int main()
{
	cin >> N >> M;
	G.resize(N + 1, vector<int>(N + 1, -1));
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cin >> G[a][b];
		G[b][a] = G[a][b];
	}

	for (int i = 1; i <= N; i++)
		G[i][i] = 0;

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (G[i][k] > -1 && G[k][j] > -1 && (G[i][j] == -1 || G[i][k] + G[k][j] < G[i][j]))
				{
					G[i][j] = G[i][k] + G[k][j];
				}
			}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << G[i][j] << ' ';
		}
		cout << endl;
	}
}
