#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <time.h>
using namespace std;

struct Node
{
	int value;
	int tot;
	Node *lc, *rc, *pa;
	int count0;
	int count1;

	Node(int _value, Node *_pa) : pa(_pa), value(_value) {}
	Node(int _value) : value(_value) {}
	Node() {}
};

void insert(Node * & root, int x)
{
	if (root == NULL)
	{
		root = new Node(x);
	} else
	{
		if (rand() & 1) 
		{
			if (root->rc) insert(root->rc, x);
			else root->rc = new Node(x, root);
		} else
		{
			if (root->lc) insert(root->lc, x);
			else root->lc = new Node(x, root);
		}
	}
}

void print(Node *root)
{
	if (!root) return;
	cout << root->value << ' ';
	if (root->lc) cout << root->lc->value << ' ';
	else cout << "NULL ";
	if (root->rc) cout << root->rc->value << ' ';
	else cout << "NULL ";
	cout << endl;
	print(root->lc);
	print(root->rc);
}

void maxBST(Node *root)
{
	if (!root->lc && !root->rc) 
	{
		min = max = root->value;
		maxBSTRoot = root;
		root->tot = 1;
		root->count0 = 0;
		root->count1 = 1;
		return;
	}
	if (root->lc)
	{
		if (maxBST(root->lc, true))
		maxBST(root->rc, false);
	}
	if (root->rc)
	{
		maxBST(root->rc, rmin, rmax, r);
		root->tot += root->rc->tot;
	}
	if (root->lc == l && root->rc == r)
	{
		if ((!l || root->value > lmax) && (!r || root->value < rmin))
			maxBSTRoot = root;
	}
	if (maxBSTRoot == NULL || l && l->tot > maxBSTRoot->tot) maxBSTRoot = l;
	if (maxBSTRoot == NULL || r && r->tot > maxBSTRoot->tot) maxBSTRoot = r;
}


int main()
{
	srand(time(NULL));
	Node *root = NULL;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		insert(root, x);
	}

	print(root);
		
	Node *maxBSTRoot = NULL;
	int max = INT_MAX, min = INT_MIN;
	maxBST(root, min, max, maxBSTRoot);

	cout << maxBSTRoot << endl;
	print(maxBSTRoot);
}
