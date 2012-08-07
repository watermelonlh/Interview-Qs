#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAXLEN = 5000;

int main()
{
	string S;
	cin >> S;
	string addS = "#";
	for (int i = 0; i < S.size(); i++)
		addS += S.substr(i, 1) + "#";

	vector<int> p(addS.size());
	int center = 0, farestP = 0;
	for (int i = 1; i < addS.size(); i++)
	{
		if (farestP < i || p[center - (i - center)] + i >= farestP)
		{
			if (farestP < i) farestP = i;
			int j = i - (farestP - i);
			while (j > 0 && farestP + 1 < addS.size() && addS[j - 1] == addS[farestP + 1])
			{
				farestP++;
				j--;
			}
			p[i] = farestP - i;
			center = i;
		} else
		{
			p[i] = p[center - (i - center)];
		}
	}

	int ans = 0;
	int c = 0;
	for (int i = 0; i < addS.size(); i++)
	{
//		cout << addS[i] << " p=" << p[i] << endl;
		if (p[i] > ans)
		{
			c = i;
			ans = p[i];
		}
	}

	cout << S.substr((c - ans) / 2, ans);
}

