class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strs.size();
        string ans = "";
        if (n == 0) return ans;
        ans = strs[0];
        int len = ans.size();
        for (int i = 1; i < n; i++)
        {
            len = min(len, int(strs[i].size()));
            for (int k = 0; k < len; k++)
            {
                if (strs[i][k] != ans[k])
                {
                    len = k;
                    break;
                }
            }
            ans.erase(len);
            if (len == 0) break;
        }
        return ans;
    }
};
