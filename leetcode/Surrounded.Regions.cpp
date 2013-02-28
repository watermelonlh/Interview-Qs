class Solution {
public:

    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int N = board.size();
        if (N == 0) return;
        int M = board[0].size();
        if (M == 0) return;
        vector<vector<bool> > mark(N, vector<bool>(M, false));
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (!mark[i][j] && board[i][j] == 'O')
                {
                    vector<int> queX, queY;
                    queX.push_back(i);
                    queY.push_back(j);
                    mark[i][j] = true;
                    int head = 0;
                    bool result = !(i == 0 || j == 0 || i == N - 1 || j == M - 1) ;
                    
                    while (head < queX.size())
                    {
                        int nx = queX[head];
                        int ny = queY[head];
                        head++;
                        for (int i = 0; i < 4; i++)
                        {
                            int nextX = nx + dx[i];
                            int nextY = ny + dy[i];
                            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
                            {
                                if (!mark[nextX][nextY] && board[nextX][nextY] == 'O')
                                {
                                    mark[nextX][nextY] = true;
                                    queX.push_back(nextX);
                                    queY.push_back(nextY);
                                    if (nextX == 0 || nextY == 0 || nextX == N - 1 || nextY == M - 1) 
                                        result = false;
                                }
                            }
                        }
                    }
                    if (result)
                    {
                        for (int i = 0; i < queX.size(); i++)
                            board[queX[i]][queY[i]] = 'X';
                    }
                }
            }
    }
};
