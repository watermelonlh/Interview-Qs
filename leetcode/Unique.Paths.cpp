class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > F(m, vector<int>(n, 0));
        F[0][0] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (i) F[i][j] += F[i - 1][j];
                if (j) F[i][j] += F[i][j - 1];
            }
        return F[m - 1][n - 1];
    }
};
