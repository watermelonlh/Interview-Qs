#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> num;


void down(int now)
{
	int low = (now + 1) * 2 - 1;
	while (low < N)
	{
		if (low < N - 1 && num[low + 1] < num[low]) low++;
		if (num[low] < num[now])
		{	
			swap(num[now], num[low]);
			now = low;
			low = (now + 1) * 2 - 1;
		} else
			break;
	}
}

int main()
{
	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	for (int i = N / 2; i >= 0; i--)
		down(i);

	while (N)
	{
		cout << num[0] << endl;
		N--;
		num[0] = num[N];
		down(0);
	}

}




