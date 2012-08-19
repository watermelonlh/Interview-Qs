#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


struct node
{
	int lc, rc;
	int pa;
	int height;
};
vector<node> tree;


bool isBalanced(int fa, int now)
{
	if (now == 0) return true;
	int lh, rh;
	bool res = (isBalanced(now, tree[now].lc) && isBalanced(now, tree[now].rc));
	if (tree[now].lc) lh = tree[tree[now].lc].height; else lh = 0;
	if (tree[now].rc) rh = tree[tree[now].rc].height; else rh = 0;
	tree[now].height = max(lh, rh) + 1;
	if (res && abs(lh - rh) <= 1)
		return true;
	else return false;
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
	cout << boolalpha << isBalanced(0, 1) << endl;
}

