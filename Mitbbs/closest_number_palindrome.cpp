#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int NoMoreThan(int x)
{
	int ans = 0;
	char num[11], high[6];
	int reverseHighValue;
	int l = 0;
	
	itoa(x, num, 10);
	l = strlen(num);
	strncpy(high, num, l / 2);
	high[l / 2] = '\0';
	reverseHighValue = 0;
	for (int i = l / 2 - 1; i >= 0; i--)
		reverseHighValue = reverseHighValue * 10 + high[i] - '0';
	if (reverseHighValue > atoi(num + l - l / 2))
	{
		ans = atoi(high);
		if (l & 1) ans = ans * 10 + num[l / 2] - '0';
		ans--;
		int x = ans;
		if (l & 1) x /= 10;
		while (x)
		{
			ans = ans * 10 + x % 10;
			x /= 10;
		}
	} else
	{
		for (int i = l / 2; i < l; i++)
			num[i] = num[l - 1 - i];
		ans = atoi(num);
	}
	return ans;
}

int MoreThan(int x)
{
	int ans = 0;
	char num[11], high[6];
	int l; 
	int reverseHighValue;
	
	itoa(x, num, 10);
	l = strlen(num);
	strncpy(high, num, l / 2);
	high[l / 2] = '\0';
	reverseHighValue = 0;
	for (int i = l / 2 - 1; i >= 0; i--)
		reverseHighValue = reverseHighValue * 10 + high[i] - '0';
	if (reverseHighValue < atoi(num + l + l / 2))
	{
		ans = atoi(high);
		if (l & 1) ans = ans * 10 + num[l / 2] - '0';
		ans++;
		int x = ans;
		if (l & 1) x /= 10;
		while (x)
		{
			ans = ans * 10 + x % 10;
			x /= 10;
		}
	} else
	{
		for (int i = l / 2; i < l; i++)
			num[i] = num[l - 1 - i];
		ans = atoi(num);
	}
	return ans;
}

int main()
{
	int x;
	cin >> x;
	int ans1 = NoMoreThan(x);
	int ans2 = MoreThan(x);
	int ans = (abs(ans1 - x) < abs(ans2 - x)) ? ans1 : ans2;
	cout << ans;
}