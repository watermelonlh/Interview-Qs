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

	for (int i = 0; i < N; i++)
	{
		int x = i;
		for (int j = i + 1; j < N; j++)
			if (num[j] < num[x]) x = j;
		swap(num[x], num[i]);
	}

	for (int i = 0; i < N; i++)
		cout << num[i] << endl;

}


