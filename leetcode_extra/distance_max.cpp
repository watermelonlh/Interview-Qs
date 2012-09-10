#include <iostream>
#include <vector>
using namespace std;

int N;
int A[100];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int i = 0;
	int j = N - 1;
	vector<int> L;
	L.push_back(0);
	for (int i = 1; i < N; i++)
		if (A[i] < A[L.back()]) L.push_back(i);
	int ans = 0;
	for (int k = L.size() - 1; k >= 0; k--)
	{
		i = L[k];
		while (i < j && A[j] <= A[i]) j--;
		ans = max(ans, j - i);
	}
	cout << ans << endl;
}
