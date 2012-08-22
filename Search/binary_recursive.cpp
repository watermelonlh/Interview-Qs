#include <iostream>
#include <vector>
using namespace std;


int binarySearch(vector<int> &num, int l, int r, int K)
{
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (K > num[mid]) return binarySearch(num, mid + 1, r, K);
	else return binarySearch(num, l, mid, K);
}

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
	int r = binarySearch(num, 0, N - 1, K);
	
	cout << r << endl;
	cout << num[r] << endl;
	cout << boolalpha << (num[r] == K) << endl;
}

