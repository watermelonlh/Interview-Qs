#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	int zero = 0;
	int position = 0;
	cin >> N;

	vector<long long> num(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		if (num[i] == 0) 
		{
			zero++;
			position = i;
		}
	}


	if (zero == 0)
	{
		long long p = 1;
		for (int i = 1; i < N; i++)
			p *= num[i];
		
		for (int i = 0; i < N; i++)
		{
			cout << p << endl;
			if (i < N - 1)
			{
				p /= num[i + 1];
				p *= num[i];
			}
		}
	} else if (zero == 1)
	{
		long long p = 1;
		for (int i = 0; i < N; i++)
			if (i != position) p *= num[i];

		for (int i = 0; i < N; i++)
		{
			if (i == position) cout << p << endl;
			else cout << 0 << endl;
		}
	} else
	{
		for (int i = 0; i < N; i++)
			cout << 0 << endl;
	}

}
