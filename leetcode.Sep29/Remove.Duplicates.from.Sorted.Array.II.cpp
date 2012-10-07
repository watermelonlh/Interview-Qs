class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 3) return n;
        int l = 2;
        for (int i = 2; i < n; i++)
        {
            if (A[i] != A[l - 1] || A[i] != A[l - 2])
            {
                A[l++] = A[i];
            }
        }
        return l;
    }
};
