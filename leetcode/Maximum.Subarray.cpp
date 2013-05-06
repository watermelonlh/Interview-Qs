class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = A[0], sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
        }
        return ans;
    }
};
