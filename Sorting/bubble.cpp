#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> num(N, 0);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	int i = N - 1;
	while (i)
	{
		int newI = 0;
		for (int j = 0; j < i; j++)
		{
			if (num[j] > num[j + 1]) 
			{
				swap(num[j], num[j + 1]);
				newI = j;
			}
		}
		i = newI;
	}

	for (int i = 0; i < N; i++)
		cout << num[i] << endl;

}
