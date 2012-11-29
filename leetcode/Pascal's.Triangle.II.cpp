class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans(0);
        ans.push_back(1);
        for (int i = 1; i <= rowIndex; i++)
        {
            ans.push_back(1);
            for (int k = i - 1; k >= 1; k--)
                ans[k] += ans[k - 1];
        }
        return ans;
    }
};
