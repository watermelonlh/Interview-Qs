#include <iostream>
#include <vector>
using namespace std;


struct node
{
	int lc, rc;
	int pa;
};
vector<node> tree;


int nextInOrder(int x)
{
	if (tree[x].rc > 0)
	{
		int now = tree[x].rc;
		while (tree[now].lc > 0) now = tree[now].lc;
		return now;
	} else
	{
		int pre = x;
		int now = tree[x].pa;
		while (now > 0 && tree[now].rc == pre) 
		{
			pre = now;
			now = tree[now].pa;
		}
		return now;
	}
}

int main()
{
	int N;
	cin >> N;
	tree.resize(N + 1);

	int a, b;
	for (int i = 1; i <= N; i++)
	{
		cin >> a >> b;
		tree[i].lc = a;
		tree[a].pa = i;
		tree[i].rc = b;
		tree[b].pa = i;
	}


	int x;
	cin >> x;
	cout << nextInOrder(x) << endl;
}
