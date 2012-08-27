#include <iostream>
using namespace std;

bool isLeap(int y)
{
	return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

int main()
{
	int d, m, y, dd;

	cin >> y >> m >> d >> dd;

	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeap(y)) month[1]++;

	int day = 0;
	for (int i = 0; i < m - 1; i++)
		day += month[i];
	dd = ((day % 7 + dd) % 7 + 6) % 7 + 1;
	day += d;
	day += dd - 1;
	
	cout << dd << endl;

	cout << (day - 1) / 7 + 1 << endl;
}
