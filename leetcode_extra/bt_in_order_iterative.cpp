#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct treenode
{
	int lc, rc;
	int pa;
};

treenode node[100];
bool mark[100];
int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> node[i].lc >> node[i].rc >> node[i].pa;
	}

	int now = 1;
	stack<int> s;
	while (now || !s.empty())
	{
		if (now > 0)
		{
			s.push(now);
			now = node[now].lc;
		} else
		{
			now = s.top();
			cout << now << endl;
			s.pop();
			now = node[now].rc;
		}
	}
}
