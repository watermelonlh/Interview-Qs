#include <iostream>
using namespace std;

int N, M;
int A[1000][1000];

void spiral(int A[1000][1000], int x1, int y1, int x2, int y2)
{
	if (x1 > x2 || y1 > y2) return;
	for (int i = y1; i <= y2; i++)
		cout << A[x1][i] << ' ';
	for (int i = x1 + 1; i <= x2; i++)
		cout << A[i][y2] << ' ';
	for (int i = y2 - 1; i >= y1; i--)
		cout << A[x2][i] << ' ';
	for (int i = x2 - 1; i >= x1 + 1; i--)
		cout << A[i][y1] << ' ';
	spiral(A, x1 + 1, y1 + 1, x2 - 1, y2 - 1);
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << A[i][j] << ' ';
		cout << endl;
	}

	spiral(A, 0, 0, N - 1, M - 1);
}
