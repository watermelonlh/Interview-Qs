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

	for (int gap = N / 4 * 2 + 1; gap >= 1; gap -= 2)
		for (int i = gap; i < N; i++)
			for (int j = i - gap; j >= 0 && num[j + gap] < num[j]; j -= gap)
				swap(num[j + gap], num[j]);

	for (int i = 0; i < N; i++)
		cout << num[i] << endl;
}



