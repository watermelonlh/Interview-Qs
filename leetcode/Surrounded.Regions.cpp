class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = board.size();
        if (!N) return;
        int M = board[0].size();
        if (!M) return;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {   
                if (board[i][j] == 'O')
                {
                    vector<int> queX(0);
                    vector<int> queY(0);
                    queX.push_back(i), queY.push_back(j);
                    board[i][j] = '.';
                    int head = 0;
                    bool edge = false;
                    while (head < queX.size())
                    {
                        int x = queX[head], y = queY[head];
                        if (!x || !y || x == N - 1 || y == M - 1) edge = true;
                        head++;
                        for (int i = 0; i < 4; i++)
                        {
                            int nx = x + dx[i], ny = y + dy[i];
                            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
                                if (board[nx][ny] == 'O')
                                {
                                    board[nx][ny] = '.';
                                    queX.push_back(nx);
                                    queY.push_back(ny);
                                }
                        }
                    }
                    if (edge)
                    {
                        for (int i = 0; i < queX.size(); i++)
                            board[queX[i]][queY[i]] = ',';
                    }
                }
            }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (board[i][j] == ',') board[i][j] = 'O';
                else board[i][j] = 'X';
    }
};
