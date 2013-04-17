class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign = 1;
        if (dividend < 0 ^ divisor < 0) sign = -1;
        long long d1 = dividend;
        long long d2 = divisor;
        d1 = abs(d1);
        d2 = abs(d2);
        long long p = 1;
        while (d1 >= d2)
        {
            p = p << 1;
            d2 = d2 << 1;
        }
        
        long long ans = 0;
        while (p > 1)
        {
            p = p >> 1;
            d2 = d2 >> 1;
            if (d1 >= d2)
            {
                d1 -= d2;
                ans += p;
            }
        }
        return ans * sign;
    }
};
