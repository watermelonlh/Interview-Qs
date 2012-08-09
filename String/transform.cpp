#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<string> findPath(vector<string> &allWords, vector<int> &parent)
{
	int now = parent.size() - 1;
	vector<string> ans;
	do
	{
		ans.push_back(allWords[now]);
		now = parent[now];
	} while (now);

	int len = ans.size();
	for (int i = 0; i < len / 2; i++)
		swap(ans[i], ans[len - 1 - i]);
	return ans;
}


vector<string> transform(string startWord, string endWord, vector<string> &words)
{
	set<string> dicts;
	for (int i = 0; i < words.size(); i++)
	{
		dicts.insert(words[i]);
	}

	set<string> mark;
	vector<string> allWords;
	vector<int> parent;
	allWords.push_back(startWord);
	parent.push_back(0);
	mark.insert(startWord);
	int head = 0, tail = 1;
	while (head < tail)
	{
		string now = allWords[head];
		head++;
		for (int i = 0; i < now.size(); i++)
		{
			for (char ch = 'a'; ch <= 'z'; ch++)
			{
				string tmp = now;
				tmp[i] = ch;
				if (mark.find(tmp) == mark.end() && dicts.find(tmp) != dicts.end())
				{
					mark.insert(tmp);
					allWords.push_back(tmp);
					parent.push_back(head - 1);
					if (tmp == endWord) return findPath(allWords, parent);
					tail++;
				}
			}
		}
	}

	return vector<string>(0);
}

int main()
{
	int N;
	cin >> N;
	vector<string> words(N);
	for (int i = 0; i < N; i++)
		cin >> words[i];
	
	string startWords, endWords;
	cin >> startWords;
	cin >> endWords;

	vector<string> ans = transform(startWords, endWords, words);

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}
