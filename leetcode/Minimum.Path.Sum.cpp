class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > F(n, vector<int>(m, 0));
        F[0][0] = grid[0][0];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (!i && !j) continue;
                if (i > 0 && j == 0)
                    F[i][j] = F[i - 1][j] + grid[i][j];
                else if (j > 0 && i == 0)
                    F[i][j] = F[i][j - 1] + grid[i][j];
                else 
                    F[i][j] = min(F[i][j - 1], F[i - 1][j]) + grid[i][j];
            }
        return F[n - 1][m - 1];
    }
};
