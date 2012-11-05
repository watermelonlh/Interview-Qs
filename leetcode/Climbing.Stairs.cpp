class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int f0 = 1, f1 = 1, f2 = 0;
        if (n < 2) return 1;
        for (int i = 2; i <= n; i++)
        {
            f2 = f0 + f1;
            f0 = f1, f1 = f2;
        }
        return f2;
    }
};
