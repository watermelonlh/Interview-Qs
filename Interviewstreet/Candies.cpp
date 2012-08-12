#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> rate(N, 0);
	for (int i = 0; i < N; i++)
		cin >> rate[i];

	vector<int> left(N, 1);
	vector<int> right(N, 1);
	for (int i = 1; i < N; i++)
	{
		if (rate[i] > rate[i - 1]) left[i] = left[i - 1] + 1;
	}
	for (int i = N - 2; i >= 0; i--)
	{
		if (rate[i] > rate[i + 1]) right[i] = right[i + 1] + 1;
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += max(right[i], left[i]);
	
	cout << ans << endl;
}
