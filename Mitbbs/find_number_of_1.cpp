#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	int count = 0;
	while (x)
	{
		count += x & 1;
		x >>= 1;
	}
	cout << count;
}