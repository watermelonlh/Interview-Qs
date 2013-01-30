class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<string, int> dict;
        vector<string> ans;
        int N = strs.size();
        for (int i = 0; i < N; i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            dict[s]++;
        }
        for (int i = 0; i < N; i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (dict[s] > 1) ans.push_back(strs[i]);
        }
        return ans;
    }
};

class Solution {
public:
    static bool cmp(pair<string, string> a, pair<string, string> b)
    {
        return a.first < b.first;
    }
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<pair<string, string> > word;
        vector<string> ans;
        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            word.push_back(pair<string, string>(strs[i], strs[i]));
            sort(word[i].first.begin(), word[i].first.end());
        }
        sort(word.begin(), word.end(), cmp);
        int k = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (word[i].first == word[k].first)
            {
                cnt++;
                if (cnt == 2) ans.push_back(word[k].second);
                if (cnt > 1) ans.push_back(word[i].second);
            } else
            {
                cnt = 1;
                k = i;
            }
        }
        return ans;
    }
};
