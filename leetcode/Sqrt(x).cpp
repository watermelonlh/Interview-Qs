class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long L = 1, R = x, ans = 0;
        while (L <= R)
        {
            long long mid = (L + R) / 2;
            if (mid * mid == x) 
            {
                ans = mid;
                break;
            }
            if (mid * mid < x) ans = mid, L = mid + 1;
            else R = mid - 1;
        }
        return ans;
    }
};
