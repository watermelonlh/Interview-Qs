#include <iostream>
#include <stack>
using namespace std;

class myStack
{
	stack<int> s1, s2;

	public:
		void push(int x)
		{
			s1.push(x);
			if (s2.empty() || x < s2.top()) s2.push(x);
			else s2.push(s2.top());
		}

		void pop()
		{
			s1.pop();
			s2.pop();
		}

		int top()
		{
			return s1.top();
		}

		int min()
		{
			return s2.top();
		}
};


int main()
{
	int N;
	cin >> N;

	myStack s;
	while (N > 0)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			s.pop();
		} else
		{
			s.push(x);
		}
		cout << s.top() <<  ' ' << s.min() << endl;
		N--;
	}
}
