#include <iostream>
#include <queue>
using namespace std;


class myStack
{
	queue<int> q1, q2;

	public:
		void push(int x)
		{
			if (q1.empty())
			{
				q1.push(x);
				while (!q2.empty())
				{
					q1.push(q2.front());
					q2.pop();
				}
			} else
			{
				q2.push(x);
				while (!q1.empty())
				{
					q2.push(q1.front());
					q1.pop();
				}
			}
		}

		void pop()
		{
			if (q1.empty()) q2.pop();
			else q1.pop();
		}

		int top()
		{
			if (q1.empty()) return q2.front();
			else return q1.front();
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
		cout << s.top() << endl;
		N--;
	}

}
