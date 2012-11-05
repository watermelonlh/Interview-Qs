class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            if (A[i] > ans) ans = A[i];
        
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + A[i] <= 0)
            {
                sum = 0;
            } else
            {
                sum += A[i];
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};
