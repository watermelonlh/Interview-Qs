#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int l = 0;
	while (a >= b) l++, b <<= 1;
	b >>= 1;

	int r = 0;
	for (int i = l; i >= 1; i--, b >>= 1)
		if (a >= b)
		{
			a -= b;
			r += 1 << i - 1;
		}

	cout << r << ' ' << a << endl;
	
}
