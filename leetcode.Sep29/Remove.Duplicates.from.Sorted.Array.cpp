class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 2) return n;
        int l = 1;
        for (int i = 1; i < n; i++)
        {
            if (A[i] != A[l - 1])
            {
                A[l++] = A[i];
            }
        }
        return l;
    }
};
