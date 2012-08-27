#include <iostream>
using namespace std;

int main()
{
	int x;
	int y = 0;
	cin >> x;
	int t = x;
	do
	{
		t /= 10;
		y = y * 10 + t % 10;
	} while (t);
	cout << (x == y) << endl;
}