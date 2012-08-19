#include <iostream>
#include <vector>
using namespace std;


struct node
{
	int pa;
	int lc, rc;
	int value;
};

vector<node> tree;
int N;

bool isAddSum(int fa, int now, int sum)
{
	if (now == 0) return !sum;

	bool res = isAddSum(now, tree[now].lc, sum - tree[now].value);
	if (res) return res;
	return isAddSum(now, tree[now].rc, sum - tree[now].value);
}

int main()
{
	cin >> N;
	tree.resize(N + 1);

	int a, b;
	for (int i = 1; i <= N; i++)
	{
		cin >> a >> b;
		tree[i].lc = a;
		tree[i].rc = b;
		tree[a].pa = i;
		tree[b].pa = i;
	}
	for (int i = 1; i <= N; i++)
		cin >> tree[i].value;

	int sum;
	cin >> sum;

	cout << boolalpha << isAddSum(0, 1, sum) << endl;


}
