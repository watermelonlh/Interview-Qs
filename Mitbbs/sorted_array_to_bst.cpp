#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int lc, rc;
	int value;
	int pa;
};

vector<int> num;
vector<node> tree;
int nodeCount;


void buildTree(int l, int r, int fa, int now)
{
	int mid = (l + r) / 2;
	tree[now].value = num[mid];
	tree[now].pa = fa;
	tree[now].lc = tree[now].rc = 0;
	if (l <= mid - 1) 
	{
		tree[now].lc = ++nodeCount;
		buildTree(l, mid - 1, now, nodeCount);
	}
	if (mid + 1 <= r)
	{
		tree[now].rc = ++nodeCount;
		buildTree(mid + 1, r, now, nodeCount);
	}
}

int main()
{
	int N;
	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	tree.resize(N + 1);
	nodeCount = 1;
	buildTree(0, N - 1, 0, 1);
	
	for (int i = 1; i <= N; i++)
		cout << tree[i].value << ' ' << tree[i].lc << ' ' << tree[i].rc << endl;
}