#include <iostream>
#include <vector>
using namespace std;

int maxSubsquare(vector<vector<int> > &matrix)
{
	int N = matrix.size();
	int M = matrix[0].size();
	int ans = 0;
	
	vector<vector<int> > F(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (matrix[i][j] == 1)
			{
				int tmp = 1 << 30;
				if (i > 0 && j > 0 && F[i - 1][j - 1] < tmp) tmp = F[i - 1][j - 1];
				if (i > 0 && F[i - 1][j] < tmp) tmp = F[i - 1][j];
				if (j > 0 && F[i][j - 1] < tmp) tmp = F[i][j - 1];
				if (tmp == 1 << 30) tmp = 0;
				F[i][j] = tmp + 1;
				if (F[i][j] > ans) ans = F[i][j];
			} 
		}
	return ans;
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int> > matrix(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> matrix[i][j];
			
	cout << maxSubsquare(matrix);
}