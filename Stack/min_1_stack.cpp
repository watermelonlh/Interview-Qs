#include <iostream>
#include <stack>
using namespace std;

struct ValueMinPair
{
	int value, minValue;

	ValueMinPair(int a, int b) : value(a), minValue(b) {};
};


class myStack
{
	stack<ValueMinPair> s1;

	public:
		void push(int x)
		{
			ValueMinPair tmp(x, x);
			if (!s1.empty() && s1.top().minValue < tmp.minValue) 
				tmp.minValue = s1.top().minValue;
			s1.push(tmp);
		}

		void pop()
		{
			s1.pop();
		}

		int top()
		{
			return s1.top().value;
		}

		int min()
		{
			return s1.top().minValue;
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

