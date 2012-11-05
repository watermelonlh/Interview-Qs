class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 2) return 0;
        for (int i = 1; i < n; i++)
        {
            if (left[i - 1] > A[i]) left[i] = left[i - 1]; else left[i] = A[i];
        }
        right[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (right[i + 1] > A[i]) right[i] = right[i + 1]; else right[i] = A[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += min(right[i], left[i]) - A[i];
        }
        return ans;
    }
};
