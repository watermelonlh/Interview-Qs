class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (target > A[n - 1]) return n;
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (A[mid] < target) l = mid + 1;
            else r = mid;
        }
        return r;
    }
};
