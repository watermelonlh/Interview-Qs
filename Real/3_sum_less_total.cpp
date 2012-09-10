#include <iostream>
#include <algorithm>
using namespace std;


int N;
int A[100];
int target;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> target;

	int ans = 0;
	sort(A, A + N);
	for (int L = 0, R = N - 1; L < R - 1; L++)
	{
		while (L < R - 1 && A[L] + A[R] >= target) R--;
		if (L < R - 1)
		{
			int goal = target - A[L] - A[R];
			int l = L, r = R;
			while (l < r)
			{
				int mid = (l + r) / 2;
				if (A[mid] < goal) l = mid + 1;
				else r = mid;
			}
			r--;
			if (r > L) ans += r - L;
		}
		cout << L << ' ' << R << ' ' << ans << endl;
	}

	cout << ans << endl;
}
