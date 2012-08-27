#include <iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	int i = 0;
	int carry = 0;
	int ans = 0;
	while (x || y || carry)
	{
		int a = x & 1;
		int b = y & 1;
		ans |= (carry ^ a ^ b) << i;
		carry = (a & carry) | (b & carry) | (a & b);
		i++;
		x >>= 1;
		y >>= 1;
	}
	cout << ans;
}