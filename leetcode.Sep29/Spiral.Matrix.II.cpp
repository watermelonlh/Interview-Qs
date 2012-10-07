class Solution {
public:
    void generate(int &num, int x1, int y1, int x2, int y2, vector<vector<int> > &ans)
    {
        if (x1 > x2 || y1 > y2) return;
        for (int y = y1; y <= y2; y++)
            ans[x1][y] = num++;
        for (int x = x1 + 1; x <= x2; x++)
            ans[x][y2] = num++;
        if (x2 > x1) 
            for (int y = y2 - 1; y >= y1; y--)
                ans[x2][y] = num++;
        if (y2 > y1)
            for (int x = x2 - 1; x >= x1 + 1; x--)
                ans[x][y1] = num++;
        generate(num, x1 + 1, y1 + 1, x2 - 1, y2 - 1, ans);
        
    }
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans(n, vector<int>(n, 0));
        int num = 1;
        generate(num, 0, 0, n - 1, n - 1, ans);
        return ans;
    }
};
