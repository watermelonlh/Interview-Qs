class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = n + m;
        int a = m - 1, b = n - 1;
        while (a >= 0 && b >= 0)
        {
            if (A[a] > B[b])
            {
                A[l - 1] = A[a];
                a--;
            } else
            {
                A[l - 1] = B[b];
                b--;
            }
            l--;
        }
        while (b >= 0)
        {
            A[l - 1] = B[b];
            b--;
            l--;
        }
    }
};
