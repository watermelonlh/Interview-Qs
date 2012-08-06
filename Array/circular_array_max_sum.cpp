#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	int l = 0, r = 0;
	int sum = 0, ans = 0;
	bool quit = false;
	while (l < N && !quit)
	{
		while (sum + A[r] > 0) 
		{
			sum += A[r];
			if (sum > ans) ans = sum;
			r = (r + 1) % N;
			if (r == l) 
			{
				quit = true;
				break;
			}
		}
		if (r + 1 <= l) break;
		l = r + 1;
		r = l;
		sum = 0;
	}
	cout << ans << endl;
}
