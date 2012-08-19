#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int lc, rc;
	int pa;
};

vector<node> tree;
vector<int> dep;
int N;
int len;

int getLca(int a, int b)
{
	while (dep[a] > dep[b]) a = tree[a].pa;
	while (dep[b] > dep[a]) b = tree[b].pa;
	while (a != b)
	{
		a = tree[a].pa;
		b = tree[b].pa;
	}
	return a;
}

void getDepth(int fa, int now, int depth)
{
	if (now == 0) return;
	dep[now] = depth;
	getDepth(now, tree[now].lc, depth + 1);
	getDepth(now, tree[now].rc, depth + 1);
}

int main()
{
	cin >> N;
	tree.resize(N + 1);
	dep.resize(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> tree[i].lc >> tree[i].rc;
		tree[tree[i].lc].pa = i;
		tree[tree[i].rc].pa = i;
	}

	getDepth(0, 1, 1);

	int M;
	cin >> M;
	int a, b;
	while (M--)
	{
		cin >> a >> b;
		cout << getLca(a, b) << endl;
	}
}
