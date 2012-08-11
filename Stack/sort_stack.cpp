#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &S)
{
	stack<int> T;

	while (!S.empty())
	{
		int now = S.top();
		S.pop();
		while (!T.empty() && now < T.top())
		{
			S.push(T.top());
			T.pop();
		}
		T.push(now);
	}
	while (!T.empty())
	{
		S.push(T.top());
		T.pop();
	}
}

int main()
{
	int N;
	cin >> N;
	stack<int> S;
	while (N--)
	{
		int x;
		cin >> x;
		S.push(x);
	}

	sortStack(S);

	while (!S.empty())
	{
		cout << S.top() << endl;

		S.pop();
	}
}
