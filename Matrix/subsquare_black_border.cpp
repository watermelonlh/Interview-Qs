#include <iostream>
#include <vector>
using namespace std;

int maxSquareBlackBorder(vector<vector<int> > &matrix)
{
	int N = matrix.size();
	int M = matrix[0].size();

	vector<vector<int> > down(N, vector<int>(M, 0));
	vector<vector<int> > left(N, vector<int>(M, 0));

	for (int i = N - 1; i >= 0; i--)
		for (int j = M - 1; j >= 0; j--)
		{
			if (matrix[i][j] == 0) left[i][j] = down[i][j] = 0;
			else 
			{
				if (j < M - 1) left[i][j] = left[i][j + 1] + 1; else left[i][j] = 1;
				if (i < N - 1) down[i][j] = down[i + 1][j] + 1; else down[i][j] = 1;
			}
		}

	for (int l = min(N, M); l >= 1; l--)
	{
		for (int i = 0; i + l - 1 < N; i++)
			for (int j = 0; j + l - 1 < M; j++)
			{
				if (matrix[i][j] == 0) continue;
				int x = i + l - 1, y = j + l - 1;
				if (down[i][j] >= l && down[i][y] >= l && left[i][j] >= l && left[x][j] >= l)
				{
					return l;
				}
			}
	}
	return 0;
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int> > matrix(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> matrix[i][j];
		}

	cout << maxSquareBlackBorder(matrix);
}
