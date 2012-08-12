#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> dict;

struct myPair
{
	string term;
	int count;

	myPair(string a, int b) : term(a), count(b) {}
};

bool cmp(myPair a, myPair b)
{
	return (a.count > b.count || (a.count == b.count && a.term < b.term));
}

int main()
{
	int N;
	int K;
	string term;
	cin >> N;
	while (N--)
	{
		cin >> term;
		dict[term]++;
	}
	cin >> K;

	vector<myPair> sortDict;
	int tot = 0;
	for (map<string, int>::iterator itr = dict.begin(); itr != dict.end(); itr++)
	{
		sortDict.push_back(myPair(itr->first, itr->second));
		tot++;
	}

	sort(sortDict.begin(), sortDict.end(), cmp);

	for (int i = 0; i < min(tot, K); i++)
		cout << sortDict[i].term << endl;
}
