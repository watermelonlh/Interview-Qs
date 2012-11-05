class Solution {
public:
    double power(double x, int n)
    {
        if (!n) return 1;
        double res = power(x, n / 2);
        res = res * res;
        if (n & 1) res *= x;
        return res;
    }
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 0)
        {
            return 1.0 / power(x, -n);
        } else
        {
            return power(x, n);
        }
    }
};
