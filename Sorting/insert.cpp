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
		for (int j = i - 1; j >= 0 && num[j + 1] < num[j]; j--)
			swap(num[j + 1, num[j]]);

	for (int i = 0; i < N; i++)
		cout << num[i] << endl;

}

