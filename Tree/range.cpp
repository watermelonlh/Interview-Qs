#include <iostream>
#include <vector>
using namespace std;


struct node
{
	int lc, rc;
	int value;
	int pa;
};
vector<node> tree;


void range(int k1, int k2, vector<int> &ans, int fa, int now)
{
	if (now == 0) return;
	if (tree[now].value >= k1) range(k1, k2, ans, now, tree[now].lc);
	if (tree[now].value >= k1 && tree[now].value <= k2) ans.push_back(tree[now].value);
	if (tree[now].value <= k2) range(k1, k2, ans, now, tree[now].rc);
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
	for (int i = 1; i <= N; i++)
		cin >> tree[i].value;


	int k1, k2;
	cin >> k1 >> k2;
	vector<int> ans;
	range(k1, k2, ans, 0, 1);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ' ;
	cout << endl;
}

