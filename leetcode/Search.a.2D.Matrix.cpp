class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = matrix.size();
        if (N == 0) return false;
        int M = matrix[0].size();
        if (M == 0) return false;
        int x = N - 1, y = 0;
        while (x >= 0 && y < M)
        {
            if (matrix[x][y] == target) return true;
            if (target > matrix[x][y]) y++;
            else x--;
        }
        return false;
    }
};
