#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> num;
vector<int> myCopy;


void merge(int l, int r)
{
	if (l >= r) return;

	int mid = (l + r) / 2;
	merge(l, mid);
	merge(mid + 1, r);

	int x = l;
	int y = mid + 1;
	for (int i = l; i <= r; i++)
	{
		if (y > r || (x <= mid && num[x] < num[y])) myCopy[i] = num[x++];
		else myCopy[i] = num[y++];
	}
	for (int i = l; i <= r; i++)
		num[i] = myCopy[i];
}

int main()
{
	cin >> N;
	num.resize(N);
	myCopy.resize(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	merge(0, N - 1);

	for (int i = 0; i < N; i++)
		cout << num[i] << endl;

}





