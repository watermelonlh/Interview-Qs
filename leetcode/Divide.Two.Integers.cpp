class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign = 1;
        if (dividend < 0 ^ divisor < 0) sign = -1;
        long long a = dividend;
        long long b = divisor;
        a = abs(a);
        b = abs(b);
        long long p = 1;
        while (a >= b)
        {
            p = p * 2;
            b = b * 2;
        }
        int ans = 0;
        while (p)
        {
            b /= 2;
            p /= 2;
            if (a >= b)
            {
                a -= b;
                ans += p;
            }
        }
        return ans * sign;
    }
};
