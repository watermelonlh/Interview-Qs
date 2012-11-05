class Solution {
public:
    double kth(int A[], int n, int B[], int m, int k)
    {
        if (m == 0) return A[k - 1];
        if (n == 0) return B[k - 1];
        int la = 0, lb = 0;
        while (true)
        {
            int i = double(n - la) / (n - la + m - lb) * (k - 1);
            int j = k - 1 - i;
            i += la, j += lb;
            int ai = (i < n) ? A[i] : INT_MAX;
            int bj = (j < m) ? B[j] : INT_MAX;
            int ai_1 = (i > 0) ? A[i - 1] : INT_MIN;
            int bj_1 = (j > 0) ? B[j - 1] : INT_MIN;
            if (ai >= bj_1 && ai <= bj) return ai;
            if (bj >= ai_1 && bj <= ai) return bj;
            if (ai < bj_1)
            {
                k -= i - la + 1;
                la = i + 1;
            } else
            {
                k -= j - lb + 1;
                lb = j + 1;
            }
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((n + m) & 1) return kth(A, m, B, n, (n + m + 1) / 2);
        else return (kth(A, m, B, n, (n + m) / 2) + kth(A, m, B, n, (n + m) / 2 + 1)) / 2.0;
    }
};
