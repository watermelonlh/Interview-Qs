class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int N = matrix.size();
        if (N == 0) return;
        int M = matrix[0].size();
        if (M == 0) return;
        
        bool r = false, c = false;
        for (int i = 0; i < N; i++)
            if (matrix[i][0] == 0)
            {
                c = true;
                break;
            }
        for (int j = 0; j < M; j++)
            if (matrix[0][j] == 0)
            {
                r = true;
                break;
            }
        for (int i = 1; i < N; i++)
            for (int j = 1; j < M; j++)
            {
                if (matrix[i][j] == 0) 
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        for (int i = 1; i < N; i++)
            if (matrix[i][0] == 0)
            {
                for (int j = 0; j < M; j++)
                    matrix[i][j] = 0;
            }
        for (int j = 1; j < M; j++)
            if (matrix[0][j] == 0)
            {
                for (int i = 0; i < N; i++)
                    matrix[i][j] = 0;
            }
        if (r) 
            for (int j = 0; j < M; j++) matrix[0][j] = 0;
        if (c)
            for (int i = 0; i < N; i++) matrix[i][0] = 0;
    }
};
