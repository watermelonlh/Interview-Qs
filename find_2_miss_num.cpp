#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int N;
	vector<int> num(N - 2);
	cin >> N;
	for (int i = 0; i < N - 2; i++)
		cin >> num[i];
	
	int x = 0;
	for (int i = 0; i < N; i++)
		x ^= i;  
	x = x ^ (x - 1);
	x ^= (x >> 1);
	
	int a = 0, b = 0;
	for (int i = 0; i < N - 2; i++)
		if (num[i] & x) a ^= num[i];
		else b ^= num[i];
	cout << a << endl;
	cout << b << endl;
	
}
