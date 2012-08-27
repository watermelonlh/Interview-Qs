#include <iostream>
using namespace std;

int N;
int A[100][100];

int main()
{
	cin >> N;

	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};

	int x = 0, y = -1;	
	int step = 0;
	int d = 0;
	int len = N;
	for (int i = 1; i <= N * N;)
	{
		for (int k = 0; k < len; k++)
		{
			x += dx[d], y += dy[d];
			A[x][y] = i++;
		}
		step++;
		if (step & 1) len--;
		d = (d + 1) % 4; 
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
}
