#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N;
	cin >> M;
	vector<vector<int> > A(N, vector<int>(M, 0));

	int num = 0, x = 0, y = 0;
	int dx = 1, dy = -1;
	while (true)
	{
		for ( ; x >= 0 && x < N && y >= 0 && y < M; x += dx, y += dy)
			A[x][y] = ++num;
		if (num == N * M) break;
		if (dx == 1) y++; else x++;
		dx = -dx, dy = -dy;
		while (x < 0 || x >= N || y < 0 || y >= M) 
			x += dx, y += dy;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << A[i][j] << ' ';
		cout << endl;
	}
}
