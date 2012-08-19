#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int lc, rc;
	int pa;
};

vector<node> tree;
int N;

int diameter(int fa, int now, int &ans)
{
	if (now == 0) return 0;
	int lcDepth = diameter(now, tree[now].lc, ans);
	int rcDepth = diameter(now, tree[now].rc, ans);
	if (tree[now].lc) lcDepth++;
	if (tree[now].rc) rcDepth++;
	if (lcDepth + rcDepth > ans) 
	{
		ans = lcDepth + rcDepth;
		cout << "@node " << now << endl;
	}
	return max(lcDepth, rcDepth);
}

int main()
{
	cin >> N;
	int a, b;
	tree.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> a >> b;
		tree[i].lc = a;
		tree[i].rc = b;
		tree[a].pa = i;
		tree[b].pa = i;
	}

	int ans = 0;
	diameter(0, 1, ans);
	cout << ans << endl;

}
