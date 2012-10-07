class Solution {
public:
    void subsets(int now, vector<int> &S, vector<int> &tuple, vector<vector<int> > &ans)
    {
        if (now == S.size())
        {
            ans.push_back(tuple);
            return;
        }
        for (int i = now; i < S.size(); i++)
        {
            if (i > now && S[i] == S[i - 1]) continue;
            tuple.push_back(S[i]);
            subsets(i + 1, S, tuple, ans);
            tuple.pop_back();
        }
        subsets(S.size(), S, tuple, ans);
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector<vector<int> > ans;
        vector<int> tuple;
        subsets(0, S, tuple, ans);
        return ans;
    }
};
