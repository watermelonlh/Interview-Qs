#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int value;
	Node *lc, *rc, *pa;

	Node(int _value, Node *_pa) : pa(_pa), value(_value) {}
	Node(int _value) : value(_value) {}
	Node() {}
};


vector<Node *> depNode[1000];


void insert(Node * & root, int x)
{
	if (root == NULL)
	{
		root = new Node(x);
	} else
	{
		if (x > root->value) 
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

void print_root(Node *root, int dep)
{
	if (root == NULL) return;
	print_root(root->lc, dep + 1);
	depNode[dep].push_back(root);
	print_root(root->rc, dep + 1);
}

int main()
{
	Node *root = NULL;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		insert(root, x);
	}
		
		
	print_root(root, 1);
	
	for (int i = 1; i <= N; i++)
	{
		if (i & 1)
		{
			for (int k = 0; k < depNode[i].size(); k++)
				cout << depNode[i][k]->value  << ' ';
			cout << endl;
		} else
		{
			for (int k = depNode[i].size() - 1; k >= 0; k--)
				cout << depNode[i][k]->value << ' ';
			cout << endl;
		}
	}
}
