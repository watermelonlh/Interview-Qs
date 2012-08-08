#include <iostream>
#include <set>
using namespace std;

multiset<int> smaller, bigger;
int N;
int tot = 0;


void adjust()
{
	while (smaller.size() < bigger.size())
	{
		multiset<int>::iterator itr = bigger.begin();
		smaller.insert(*itr);
		bigger.erase(itr);
	}
	while (smaller.size() > bigger.size() + 1)
	{
		multiset<int>::iterator itr = smaller.end();
		itr--;
		bigger.insert(*itr);
		smaller.erase(itr);
	}
	if (tot & 1) cout << *smaller.rbegin() << endl;
	else 
	{
		long long sum = *smaller.rbegin();
		sum += *bigger.begin();
		if (sum < 0) 
		{
			cout << '-';
			sum = -sum;
		}
		cout << sum / 2;
		if (sum % 2 == 1) cout << ".5" << endl; else cout << endl;
	}
}

bool doRemove(const int &x)
{
	if (smaller.empty()) return false;
	if (*smaller.rbegin() >= x)
	{
		multiset<int>::iterator itr = smaller.find(x);
		if (itr == smaller.end()) return false;
		smaller.erase(itr);
	} else
	{
		multiset<int>::iterator itr = bigger.find(x);
		if (itr == bigger.end()) return false;
		bigger.erase(itr);
	}
	tot--;
	if (tot == 0) return false;
	adjust();
	return true;
}

void doAdd(const int &x)
{
	if (smaller.empty()) smaller.insert(x);
	else 
	{
		if (x > *smaller.rbegin())	bigger.insert(x);
		else smaller.insert(x);
	}
	tot++;
	adjust();
}



void process(const char &cmd, const int &x)
{
	if (cmd == 'r') 
	{
		if (!doRemove(x)) cout << "Wrong!" << endl;
	}
	else
	{
		doAdd(x);
	}
}

int main()
{
	cin >> N;
	while (N)
	{
		char cmd;
		int x;
		cin >> cmd >> x;
		process(cmd, x);
		N--;
	}
}
