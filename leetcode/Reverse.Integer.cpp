class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sign;
        if (x < 0) x = -x, sign = -1; else sign = 1;
        long long y = 0;
        while (x)
        {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y * sign;
    }
};
