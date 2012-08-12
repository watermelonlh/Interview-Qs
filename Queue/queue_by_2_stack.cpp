#include <iostream>
#include <stack>
using namespace std;



class myQueue
{
	stack<int> s1, s2;

	public:
		void push(int x)
		{
			while (!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
			s2.push(x);
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}

		void pop()
		{
			s2.pop();
		}

		int front()
		{
			return s2.top();
		}

		int back()
		{
			int res;
			while (!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
			res = s1.top();
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			return res;
		}
};



int main()
{
	int N;
	cin >> N;

	myQueue s;
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
		cout << s.front() <<  ' ' << s.back() << endl;
		N--;
	}

}
