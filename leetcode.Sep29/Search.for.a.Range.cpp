class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans(2);
        ans[0] = -1, ans[1] = -1;
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (A[mid] < target) l = mid + 1;
            else r = mid;
        }
        if (A[r] == target) ans[0] = r;
        else return ans;
        l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (A[mid] < target + 1) l = mid + 1;
            else r = mid;
        }
        if (A[r] > target) ans[1] = r - 1;
        else ans[1] = r;
        return ans;
    }
};
