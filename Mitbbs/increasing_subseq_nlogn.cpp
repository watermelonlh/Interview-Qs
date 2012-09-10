#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	vector<int> A;
	cin >> N;
	A.resize(N, 0);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	vector<int> D(1);
	vector<int> F(N);
	D.push_back(A[0]);
	F[0] = 1;
	int ans = 1;
	for (int i = 1; i < N; i++)
	{
		int L = 1, R = ans;
		while (L < R)
		{
			int mid = (L + R) >> 1;
			if (A[i] > D[mid]) L = mid + 1;
			else R = mid;
		}
//		cout << "R = " << R << ' ' << D[R] << endl;
		if (A[i] <= D[R]) R--;
//		cout << "R = " << R << endl;
		int k = R + 1;
//		cout << "k = " << k << endl;
		if (k == D.size()) D.push_back(A[i]);
		else if (A[i] < D[k]) D[k] = A[i];
		if (k > ans) ans = k;
	}

	cout << ans << endl;
}
