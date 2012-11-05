class Solution {
public:
    bool solve(int x, int y, vector<vector<char> > &board, vector<int> &column, vector<int> &row, vector<int> &block)
    {
        if (x == 9)
        {   
            return true;
        }
        if (board[x][y] == '.')
        {
            int b = x / 3 * 3 + y / 3;
            for (int i = 1; i <= 9; i++)
            {
                if (column[y] & (1 << i)) continue;
                if (row[x] & (1 << i)) continue;
                if (block[b] & (1 << i)) continue;
                column[y] = column[y] | (1 << i);
                row[x] = row[x] | (1 << i);
                block[b] = block[b] | (1 << i);
                board[x][y] = '0' + i;
                if (y == 8) 
                { 
                    if (solve(x + 1, 0, board, column, row, block)) return true;
                }
                else 
                {
                    if (solve(x, y + 1, board, column, row, block)) return true;
                }
                board[x][y] = '.';   
                column[y] = column[y] ^ (1 << i);
                row[x] = row[x] ^ (1 << i);
                block[b] = block[b] ^ (1 << i);                
            }
        } else
        {
                if (y == 8) 
                { 
                    if (solve(x + 1, 0, board, column, row, block)) return true;
                }
                else 
                {
                    if (solve(x, y + 1, board, column, row, block)) return true;
                }
        }
        return false;
    }
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> column(9, 0), row(9, 0), block(9, 0);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;
                int x = board[i][j] - '0';
                int b = i / 3 * 3 + j / 3;
                column[j] = column[j] | (1 << x);
                row[i] = row[i] | (1 << x);
                block[b] = block[b] | (1 << x);
            }
        solve(0, 0, board, column, row, block);
    }
};
