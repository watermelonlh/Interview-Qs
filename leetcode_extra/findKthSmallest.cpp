#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, M;
int A[1000], B[1000];

int theKth(int K, int A[], int N, int B[], int M)
{
	int i = (int)((double) N / (N + M) * (K - 1));
	int j = K - 1 - i;
	
	int Ai = (i == N) ? INT_MAX: A[i];
	int Bj = (j == M) ? INT_MAX: B[j];
	int Ai_1 = (i) ? A[i - 1] : INT_MIN;
	int Bj_1 = (j) ? B[j - 1] : INT_MIN;

	cout << i << ' ' << j << ' ' << K << endl;
	cout << Ai_1 << ' ' << Ai << ' ' << Bj_1 <<  ' ' << Bj << endl;

	if (Bj_1 < Ai && Ai < Bj)
	{
		return Ai;
	}
	if (Ai_1 < Bj && Bj < Ai)
	{
		return Bj;
	}
	if (Ai < Bj_1) return theKth(K - i - 1, A + i + 1, N - i - 1, B, j);
	else return theKth(K - j - 1, A, i, B + j + 1, M - j - 1);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> B[i];
	
	int K;
	cin >> K;
	cout << theKth(K, A, N, B, M);
}
