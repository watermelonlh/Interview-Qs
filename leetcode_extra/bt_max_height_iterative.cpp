#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct treenode
{
	int lc, rc;
	int pa;
	int height;
};

treenode node[100];
int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> node[i].lc >> node[i].rc >> node[i].pa;
	}

	int now = 1;
	int ans = 0;
	list<int> nodeList;
	nodeList.push_back(1);
	node[1].height = 1;
	while (!nodeList.empty())
	{
		int now = nodeList.front();
		nodeList.pop_front();
		ans = max(ans, node[now].height);
		if (node[now].lc > 0)
		{
			nodeList.push_back(node[now].lc);
			node[node[now].lc].height = node[now].height + 1;
		}
		if (node[now].rc > 0)
		{
			nodeList.push_back(node[now].rc);
			node[node[now].rc].height = node[now].height + 1;
		}
	}
	cout << ans << endl;
}
