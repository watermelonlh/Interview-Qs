#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct node
{
	int lc, rc;
	int height;
	int pa;
};

int N;
vector<node> tree;

void preOrder(int fa, int now)
{
	if (now == 0) return;
	tree[now].pa = fa;
	cout << now << ' ';
	preOrder(now, tree[now].lc);
	preOrder(now, tree[now].rc);
}

void inOrder(int fa, int now)
{
	if (now == 0) return;
	tree[now].pa = fa;
	inOrder(now, tree[now].lc);
	cout << now << ' ';
	inOrder(now, tree[now].rc);
}

void postOrder(int fa, int now)
{
	if (now == 0) return;
	tree[now].pa = fa;
	postOrder(now, tree[now].lc);
	postOrder(now, tree[now].rc);
	cout << now << ' ';
}

void getHeight(int fa, int now)
{
	int res = 0;
	if (tree[now].lc > 0)
	{
		getHeight(now, tree[now].lc);
		res = tree[tree[now].lc].height;
	}
	if (tree[now].rc > 0)
	{
		getHeight(now, tree[now].rc);
		res = max(res, tree[tree[now].rc].height);
	}
	tree[now].height= res + 1;
}

void setHeight(int fa, int now, int depth)
{
	if (now == 0) return;
	tree[now].height = depth;
	setHeight(now, tree[now].lc, depth - 1);
	setHeight(now, tree[now].rc, depth - 1);
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
		tree[i].rc = b;
		tree[i].pa = 0;
	}

	
	
	preOrder(0, 1);
	cout << endl;
	inOrder(0, 1);
	cout << endl;
	postOrder(0, 1);
	cout << endl;

	getHeight(0, 1);
	setHeight(0, 1, tree[1].height);
	for (int i = 1; i <= N; i++)
		printf("node #%d, height=%d\n", i, tree[i].height);

}
