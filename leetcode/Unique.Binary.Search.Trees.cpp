class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> F(n + 1, 0);
        F[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
            {
                F[i] += F[j] * F[i - 1 - j];
            }
        return F[n];
    }
};
