#include <iostream>
#include <queue>
using namespace std;


class myStack
{
	queue<int> q1;
	int tot;

	public:
		myStack() { tot = 0; } 
		void push(int x)
		{
			tot++;
			q1.push(x);
		}

		void pop()
		{
			int l = tot;
			while (l > 1)
			{
				q1.push(q1.front());
				q1.pop();
				l--;
			}
			tot--;
			q1.pop();
		}

		int top()
		{
			int l = tot;
			int res = 0;
			while (l > 0)
			{
				res = q1.front();
				q1.push(res);
				q1.pop();
				l--;
			}
			return res;
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
