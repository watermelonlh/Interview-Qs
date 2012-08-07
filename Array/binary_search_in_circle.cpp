#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	int target;
	cin >> N;
	vector<int> num(N, 0);
	for (int i = 0; i < N; i++)
		cin >> num[i];
	cin >> target;

	int l = 0, r = N - 1;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (num[mid] > num[r]) l = mid + 1;
		else r = mid;
	}

	l = r, r = l + N - 1;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (target > num[mid % N]) l = mid + 1;
		else r = mid;
	}
	cout << boolalpha << (num[r % N] == target) << endl;
}
