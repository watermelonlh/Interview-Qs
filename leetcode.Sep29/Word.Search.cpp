class Solution {
public:
    bool check(int x, int y, vector<vector<char> > &board, int N, int M, int p, string &word, vector<vector<bool> > &mark)
    {
        if (p == word.size()) return true;
        if (x < 0 || x >= N || y < 0 || y >= M) return false;
        if (board[x][y] != word[p] || mark[x][y]) return false;
        
        mark[x][y] = true;
        if (check(x + 1, y, board, N, M, p + 1, word, mark)) return true;
        if (check(x, y + 1, board, N, M, p + 1, word, mark)) return true;
        if (check(x - 1, y, board, N, M, p + 1, word, mark)) return true;
        if (check(x , y - 1, board, N, M, p + 1, word, mark)) return true;
        mark[x][y] = false;
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = board.size();
        int M = board[0].size();
        vector<vector<bool> > mark(N, vector<bool>(M, 0));
        for (int x = 0; x < N; x++)
            for (int y = 0; y < M; y++)
                if (check(x, y, board, N, M, 0, word, mark)) return true;
        return false;
    }
};
