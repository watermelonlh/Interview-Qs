#include <iostream>
using namespace std;

int main()
{
	int N;
	int L[100], R[100];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> L[i] >> R[i];

	int cL = L[0], cR = R[0];
	for (int i = 1; i < N; i++)
	{
		if (L[i] <= cR)
		{
			cL = L[i];
			cR = min(cR, R[i]);
		} else
		{
			cL = cR = -1;
			break;
		}
		 
	}
	cout << cL << ' ' << cR << endl;
}
