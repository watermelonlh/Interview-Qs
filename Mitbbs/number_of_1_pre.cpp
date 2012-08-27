#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	int count = 0;
	int one = -1;
	int t = x;
	int i = 0;
	while (t > 0)
	{
		if (!(t & 1)) count++;
		if (count > 0 && t & 1)
		{
			one = i;
			break;
		}
		i++;
		t >>= 1;
	}
	if (one == -1) one = i;
	count = one - count + 1;
	x ^= 1 << one;
	x |= (1 << one) - 1;
	x ^= (1 << one) - 1;
	x |= (1 << count) - 1;
	cout << x;
}