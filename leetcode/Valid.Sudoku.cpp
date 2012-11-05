class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> column(9, 0), row(9, 0), block(9, 0);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;
                int x = board[i][j] - '0';
                if (column[j] & (1 << x)) return false;
                if (row[i] & (1 << x)) return false;
                if (block[i / 3 * 3 + j / 3] & (1 << x)) return false;
                column[j] += 1 << x;
                row[i] += 1 << x;
                block[i / 3 * 3 + j / 3] += 1 << x;
            }
        return true;
    }
};
