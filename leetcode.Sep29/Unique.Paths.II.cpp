class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = obstacleGrid.size();
        int M = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int> > F(N, vector<int>(M, 0));
        F[0][0] = 1;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (obstacleGrid[i][j] == 1) continue;
                if (i) F[i][j] += F[i - 1][j];
                if (j) F[i][j] += F[i][j - 1];
            }
        return F[N - 1][M - 1];
    }
};
