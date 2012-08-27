#include <iostream>
#include <vector>
using namespace std;

int maxSubrect(vector<vector<int> > &matrix)
{
	int N = matrix.size();
	int M = matrix[0].size();
	int ans = 0;
	
	vector<int> height(M, 0);
	vector<int> left(M, 0);
	vector<int> right(M, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			height[j] = (matrix[i][j]) ? height[j] + 1 : 0;
			left[j] = right[j] = 0;
		}
		for (int j = 1; j < M; j++)
			if (height[j - 1] >= height[j]) left[j] = left[j - 1] + 1;
		for (int j = M - 2; j >= 0; j--)
			if (height[j + 1] >= height[j]) right[j] = right[j + 1] + 1;
		
		for (int j = 0; j < M; j++)
			if (height[j])
			{
				int width = left[j] + right[j] + 1;
				if (width * height[j] > ans) 
				{
					ans = width * height[j];
					cout << i << ' ' << j << ' ' << width << ' ' << height[j] << ' ' << left[j] << ' ' << right[j] << endl;
				}
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
			
	cout << maxSubrect(matrix);
}