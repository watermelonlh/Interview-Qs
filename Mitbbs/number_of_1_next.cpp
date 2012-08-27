#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	int count = 0;
	int zero = -1;
	int t = x;
	int i = 0;
	while (t > 0)
	{
		if (t & 1) 
		{
			count++;
		}
		if (count > 0 && !(t & 1)) 
		{
			zero = i;
			break;
		}
		t >>= 1;
		i++;
	}
	if (zero == -1) zero = i;
	
	x += 1 << zero;
	count--;
	x |= (1 << zero) - 1;
	x ^= (1 << zero) - 1;
	x |= (1 << count) - 1;
	cout << x;
}