#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

int N;
pair<string, string> pairs[100];
map<string, vector<string>> number;
string str[100];
vector<int> edge[100];
int in[100];

void print_tree(int now, int dep)
{
	for (int i = 0; i < dep - 1; i++) cout << ' ';
	if (dep > 0) cout << "--";
	cout << str[now] << endl;
	for (int i = 0; i < edge[now].size(); i++)
	{
		print_tree(edge[now][i], dep + 1);		
	}
}


int main()
{
	cin >> N;
	int tot = 0;
	memset(in, 0, sizeof(in));
	for (int i = 0; i < N; i++)
	{
		cin >> pairs[i].first >> pairs[i].second;
		cout << number[pairs[i].first] << endl;
		if (number[pairs[i].first] == 0) { cout << "hey" << endl; number[pairs[i].first] = ++tot; str[tot] = pairs[i].first; }
		if (number[pairs[i].second] == 0) { number[pairs[i].second] = ++tot; str[tot] = pairs[i].second; }
		int a = number[pairs[i].first], b = number[pairs[i].second];
		cout << number[pairs[i].first] << endl;
		in[b]++;
		edge[a].push_back(b);
	}

	for (int i = 1; i <= N; i++)
		cout << edge[i].size() << endl;

	
	int root = 0;
	for (int i = 1; i <= N; i++)
		if (in[i] == 0) 
		{
			root = i;
			break;
		}
	
	print_tree(root, 0);
}


