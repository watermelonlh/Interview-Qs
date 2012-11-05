class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (A[mid] == target) return mid;
            if (A[mid] >= A[l])
            {
                if (target >= A[l] && target <= A[mid]) r = mid - 1;
                else l = mid + 1;
            } else
            {
                if (target >= A[mid] && target <= A[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};
