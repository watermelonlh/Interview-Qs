#include <iostream>
#include <vector>
using namespace std;

int maxSumSubmatrix(vector<vector<int> > &matrix)
{
	int N = matrix.size();
	int M = matrix[0].size();
	vector<vector<int> > sum(N, vector<int>(M, 0));
	for (int j = 0; j < M; j++)
		for (int i = 0; i < N; i++)
			sum[i][j] = (i > 0) ? sum[i - 1][j] + matrix[i][j] : matrix[i][j];

	int ans = 0;
	vector<int> sumColumn(M);
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
		{	
			for (int k = 0; k < M; k++)
				sumColumn[k] = (i > 0) ? sum[j][k] - sum[i - 1][k] : sum[j][k];
			
			int l = 0, r = 0;
			int curSum = 0;
			while (l < M)
			{
				while (r < M && curSum + sumColumn[r] >= 0) 
				{
					curSum += sumColumn[r];
					if (curSum > ans) 
					{
						ans = curSum;
						cout << i << ' ' << j << ' ' << l << ' ' << r << endl;
					}
					r++;
				}
				l = r + 1;
				r = l;
			}
		}
	return ans;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int> > matrix(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> matrix[i][j];
		}

	cout << maxSumSubmatrix(matrix);
}
