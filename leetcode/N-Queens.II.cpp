class Solution {
public:
    void solve(int &column, int &dia, int &cdia, int x, int n, int &ans)
    {
        if (x > n)
        {
            ans++;
            return;
        }
        
        for (int y = 1; y <= n; y++)
        {
            if (column & (1 << y)) continue;
            if (dia & (1 << (x - y + n - 1))) continue;
            if (cdia & (1 << (x + y - 2))) continue;
            column = column | (1 << y);
            dia = dia | 1 << (x - y + n - 1);
            cdia = cdia | 1 << (x + y - 2);
            solve(column, dia, cdia, x + 1, n, ans);
            column = column ^ (1 << y);
            dia = dia ^ 1 << (x - y + n - 1);
            cdia = cdia ^ 1 << (x + y - 2);
        }
    }
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int column = 0, dia = 0, cdia = 0;
        int ans = 0;
        solve(column, dia, cdia, 1, n, ans);
        return ans;
    }
};
