#include <iostream>
using namespace std;

int main()
{
	int N;
	int num[100];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	int L = 0;
	int ansL, ansR;
	int sum = 0;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (sum + num[i] >= 0) sum += num[i];
		else 
		{
			sum = 0;
			L = i + 1;
		}
		if (sum > ans)
		{
			ans = sum;
			ansL = L, ansR = i;
		}
	}
	if (sum > ans) ans = sum;
	cout << ans << endl;
	cout << ansL << ' ' << ansR << endl;
}
