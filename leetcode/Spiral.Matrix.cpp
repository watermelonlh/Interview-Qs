class Solution {
public:
    void spiral(int x1, int y1, int x2, int y2, vector<vector<int> > &matrix, vector<int> &ans)
    {
        if (x1 > x2 || y1 > y2) return;
        for (int y = y1; y <= y2; y++)
            ans.push_back(matrix[x1][y]);
        for (int x = x1 + 1; x <= x2; x++)
            ans.push_back(matrix[x][y2]);
        if (x1 < x2)
            for (int y = y2 - 1; y >= y1; y--)
                ans.push_back(matrix[x2][y]);
        if (y1 < y2)
            for (int x = x2 - 1; x >= x1 + 1; x--)
                ans.push_back(matrix[x][y1]);
        spiral(x1 + 1, y1 + 1, x2 - 1, y2 - 1, matrix, ans);
    }
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        int N = matrix.size();
        if (N == 0) return ans;
        int M = matrix[0].size();
        if (M == 0) return ans;
        spiral(0, 0, N - 1, M - 1, matrix, ans);
        return ans;
    }
};
