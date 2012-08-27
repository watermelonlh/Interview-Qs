#include <iostream>
using namespace std;

int N;
int A[100];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int count = 0;
	int current = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (A[current] == A[i]) count++;
		else count--;
		if (!count) current = i, count = 1;
	}

	cout << A[current] << endl;
}
