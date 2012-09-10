#include <iostream>
using namespace std;


void generate(string A, int l, int r, int N)
{
	static int tot = 0;
	if (l == N && r == N)
	{	
		tot++;
		cout << tot << ' ' << A << endl;
		return;
	}
	if (l < N) generate(A + "(", l + 1, r, N);
	if (l > r) generate(A + ")", l, r + 1, N);
}

int main()
{
	int N;
	cin >> N;

	generate("", 0, 0, N);

}
