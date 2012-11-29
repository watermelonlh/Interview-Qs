class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans(0);
        if (numRows == 0) return ans;
        ans.push_back(vector<int>(0));
        ans.back().push_back(1);
        for (int i = 2; i <= numRows; i++)
        {
            ans.push_back(vector<int>(0));
            ans.back().push_back(1);
            for (int k = 1; k < i - 1; k++)
                ans.back().push_back(ans[i - 2][k] + ans[i - 2][k - 1]);
            ans.back().push_back(1);
        }
        return ans;
    }
};
