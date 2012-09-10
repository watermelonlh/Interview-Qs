#include <iostream>
using namespace std;

int main()
{
	int N;
	int A[100];

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

//	for (int i = 0; i < N; i++)
//		cout << A[i] << endl;

	for (int k = N - 1; k >= 0; k--)
	{
		int i = k;
		while (i < N - 1 && A[i] > 0 && A[i + 1] < 0)
		{
			swap(A[i], A[i + 1]);
			i++;
		}

	}

	for (int i = 0; i < N; i++)
		cout << A[i] << endl;
}
