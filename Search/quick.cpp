#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int quick(vector<int> &num, int l, int r, int K)
{
	if (l > r) return -1;
	if (l == r)
		if (num[l] == K) return l; else return -1;
	swap(num[l], num[rand() % (r - l + 1) + l]);
	int x = num[l];
	int L = l, R = r;
	while (l < r)
	{
		while (l < r && num[r] >= x) r--;	
		num[l] = num[r];
		while (l < r && num[l] <= x) l++;
		num[r] = num[l];
	}
	num[l] = x;

	cout << L << ',' << R << endl;
	for (int i = L; i <= R; i++)
		cout << i << ' ' << num[i] << endl;
	cout << x << ' ' << l << ' ' << r << endl;
	if (x == K) return l;
	if (K > x) return quick(num, l + 1, R, K);
	else return quick(num, L, r - 1, K);
}

int main()
{
	srand(time(NULL));
	int N;
	vector<int> num;

	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	int K;
	cin >> K;
//	int r = 0;
	int r = quick(num, 0, N - 1, K);

	cout << r << endl;
	if (r > -1) cout << num[r] << endl;
}

