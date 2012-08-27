#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

void putLong(int oX)
{
	long long x = oX;
	if (x < 0) putchar('-');
	x = abs(x);
	int l = 0;
	long long p = 1;
	long long t = x;
	do
	{
		l++;
		p = p * 10;
		t /= 10;
	} while (t > 0);
	do
	{
		p /= 10;
		int t = x / p;
		putchar('0' + t);
		x -= t * p;
	} while (p > 1);
}

int main()
{
	int x;
	cin >> x;
	putLong(x);
}