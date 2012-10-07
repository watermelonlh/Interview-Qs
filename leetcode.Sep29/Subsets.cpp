class Solution {
public:
    void subset(int now, vector<int> &S, vector<int> &tuple, vector<vector<int> > &ans)
    {
        if (now == S.size())
        {
            ans.push_back(tuple);
            return;
        }
        
        for (int i = now; i < S.size(); i++)
        {
            tuple.push_back(S[i]);
            subset(i + 1, S, tuple, ans);
            tuple.pop_back();
        }
        subset(S.size(), S, tuple, ans);
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector<vector<int> > ans(0);
        vector<int> tuple(0);
        subset(0, S, tuple, ans);      
        return ans;
    }
};
