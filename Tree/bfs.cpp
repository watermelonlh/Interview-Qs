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
int len;

vector<int> bfs(int root)
{
	vector<int> levelNode;
	int head = 0, tail = 1;
	levelNode.clear();
	levelNode.push_back(root);
	while (head < tail)
	{
		int now = levelNode[head++];
		if (tree[now].lc) levelNode.push_back(tree[now].lc), tail++;
		if (tree[now].rc) levelNode.push_back(tree[now].rc), tail++;
	}
	return levelNode;
}

int main()
{
	cin >> N;
	tree.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> tree[i].lc >> tree[i].rc;
		tree[tree[i].lc].pa = i;
		tree[tree[i].rc].pa = i;
	}

	vector<int> ans = bfs(1);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
}
