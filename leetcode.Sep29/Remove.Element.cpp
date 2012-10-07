class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = n;
        for (int i = 0; i < l; i++)
        {
            if (A[i] == elem)
            {
                swap(A[i], A[l - 1]);
                l--, i--;
            }
        }
        return l;
    }
};
