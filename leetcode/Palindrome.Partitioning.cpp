class Solution {
public:

    bool isPalindrome(string s)
    {
        int l = s.size();
        for (int i = 0; i < l / 2; i++)
            if (s[l - 1 - i] != s[i]) return false;
        return true;
    }
    
    void slice(string s, int p, vector<vector<string> > &ans, vector<string> &tuple, vector<vector<bool> > &ok)
    {
        if (p == s.size())
        {
            ans.push_back(tuple);
            return;
        }
        
        for (int i = p; i < s.size(); i++)
        {
            if (ok[p][i])
            {
                tuple.push_back(s.substr(p, i - p + 1));
                slice(s, i + 1, ans, tuple, ok);
                tuple.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ans;
        vector<string> tuple;
        
        int len = s.size();
        if (len == 0) return ans;
        vector<vector<bool> > ok(len, vector<bool>(len, 0));
        
        for (int i = 0; i < len; i++)
            for (int j = i; j < len; j++)
            {
                ok[i][j] = isPalindrome(s.substr(i, j - i + 1));
            }
            
        slice(s, 0, ans, tuple, ok);
    }
};
