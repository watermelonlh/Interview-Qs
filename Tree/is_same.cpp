#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int lc, rc;
	int pa;
};

vector<node> tree, tree2;
int N;


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
	tree2.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> tree2[i].lc >> tree2[i].rc;
		tree2[tree2[i].lc].pa = i;
		tree2[tree2[i].rc].pa = i;
	}

}

