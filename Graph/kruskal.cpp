#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edgeNode
{
	int a, b;
	int w;

	edgeNode(int _a, int _b, int _w) : a(_a), b(_b), w(_w) {}
};



vector<int> P;
vector<edgeNode> edge;


bool cmp(const edgeNode &a, const edgeNode &b)
{
	return a.w < b.w;
}

int rootSet(int v)
{
	if (P[v] < 0) return v;
	else 
	{
		int rtn = rootSet(P[v]);
		P[v] = rtn;
		return rtn;
	}
}

bool mergeSet(int a, int b)
{
	a = rootSet(a);
	b = rootSet(b);
	if (a == b) return false;
	if (P[b] < P[a]) swap(a, b);
	P[a] += P[b];
	P[b] = a;
}

int main()
{
	int N, M;
	cin >> N >> M;
	edge.clear();
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edge.push_back(edgeNode(a, b, w));
	}

	int tot = 0, ans = 0;
	P.resize(N + 1, -1);
	sort(edge.begin(), edge.end(), cmp);
	for (int i = 0; i < M; i++)
		if (mergeSet(edge[i].a, edge[i].b)) 
		{
			ans += edge[i].w;
			tot++;
		}

	cout << ans << endl;
	
}
