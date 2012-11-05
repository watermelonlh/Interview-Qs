class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i0 = 0, i1 = 0, i2 = n - 1;
        while (i1 <= i2)
        {
            if (A[i1] == 0)
            {
                swap(A[i1], A[i0]);
                i0++, i1++;
            } else if (A[i1] == 2)
            {
                swap(A[i2], A[i1]);
                i2--;
            } else 
            {
                i1++;
            }
        }
    }
};
