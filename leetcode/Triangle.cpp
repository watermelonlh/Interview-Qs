class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = triangle.size();
        vector<int> ans(N, 0);
        ans[0] = triangle[0][0];
        for (int i = 1; i < N; i++)
        {
            for (int k = i; k >= 0; k--)
            {
                int left = (k) ? ans[k - 1] : INT_MAX;
                int right = (k < i) ? ans[k] : INT_MAX;
                ans[k] = triangle[i][k] + min(left, right);
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < N; i++)
            res = min(res, ans[i]);
        return res;
    }
};
