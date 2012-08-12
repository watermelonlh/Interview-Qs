#include <iostream>
#include <vector>
using namespace std;

void down(vector<int> &a, int i)
{
	int next = i << 1;
	while (next < a.size())
	{
		if (next < a.size() - 1 && a[next + 1] < a[next]) next++;
		if (a[i] > a[next])
		{
			swap(a[i], a[next]);
		} else
		{
			break;
		}
		i = next, next = i << 1;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> a(N, 0);
	for (int i = 0; i < N; i++)
		cin >> a[i];

	for (int i = N / 2; i >= 0; i--)
	{
		down(a, i);
	}

	for (int i = 0; i < N; i++)
		cout << a[i] << endl;
}
