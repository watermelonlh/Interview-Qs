#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main()
{
	int x;
	cin >> x;
	stringstream sin;
	sin << setfill('0') << setw(2) << x / 100 % 100 << "/";
	sin << setfill('0') << setw(2) << x % 100 << "/";
	sin << x / 10000;
	string d;
	sin >> d;
	cout << d << endl;


	char s[11];
	sprintf(s, "%02d/%02d/%4d", x / 100 % 100, x % 100, x / 10000);
	printf("%s\n", s);
}
