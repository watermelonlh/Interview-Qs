#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int lc, rc;
	int pa;
};

vector<node> tree;
vector<vector<int> > fa;
vector<int> dep;
int N;
int len;

void calcFa()
{
	len = 0;
	for (int l = 1, p = 1; p < N; l++, p <<= 1, len++)	
		for (int i = 1; i <= N; i++)
		{
			if (fa[i][l - 1] > 0) fa[i][l] = fa[fa[i][l - 1]][l - 1]; 
			else fa[i][l] = 0;
		}
}

int getLca(int a, int b)
{
	for (int l = len; dep[a] > dep[b] && l >= 0; l--)
		if (dep[a] - (1 << l) >= dep[b]) a = fa[a][l];
	for (int l = len; dep[b] > dep[a] && l >= 0; l--)
		if (dep[b] - (1 << l) >= dep[a]) b = fa[b][l];
	cout << "@lca " << a << ' ' << b << endl;
	for (int l = len; a != b && l > 0; l--)
		if (fa[a][l] == fa[b][l] && fa[a][l - 1] != fa[b][l - 1]) a = fa[a][l], b = fa[b][l];
	if (a != b) return fa[a][0];
	else return a;
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
	fa.resize(N + 1, vector<int>(N + 1));
	dep.resize(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> tree[i].lc >> tree[i].rc;
		tree[tree[i].lc].pa = i;
		tree[tree[i].rc].pa = i;
		if (tree[i].lc > 0) fa[tree[i].lc][0] = i;
		if (tree[i].rc > 0) fa[tree[i].rc][0] = i;
	}

	getDepth(0, 1, 1);
	calcFa();
	for (int l = 0; l <= len; l++)
	for (int i = 1; i <= N; i++)
		cout << i << ' ' << l << ' ' << fa[i][l] << endl;

	int M;
	cin >> M;
	int a, b;
	while (M--)
	{
		cin >> a >> b;
		cout << getLca(a, b) << endl;
	}
}
