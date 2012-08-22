#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	vector<int> num;

	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	int K;
	cin >> K;
	int l = 0, r = N - 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (num[r] < num[mid]) l = mid + 1;
		else r = mid;
	}

	cout << r << endl;

	l = r, r = l + N - 1;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (K > num[mid % N]) l = mid + 1;
		else r = mid;
	}

	cout << r << endl;
	cout << num[r % N] << endl;
	cout << boolalpha << (num[r % N] == K) << endl;
}


