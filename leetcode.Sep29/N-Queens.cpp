class Solution {
public:
    void solve(int &column, int &dia, int &cdia, int x, int n, vector<int> &tuple, vector<vector<string> > &ans)
    {
        if (x > n)
        {
            ans.push_back(vector<string>(0));
            string tmp(n, '.');
            for (int i = 0; i < n; i++)
            {
                tmp[tuple[i] - 1] = 'Q';
                ans.back().push_back(tmp);
                tmp[tuple[i] - 1] = '.';
            }
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
            tuple.push_back(y);
            solve(column, dia, cdia, x + 1, n, tuple, ans);
            tuple.pop_back();
            column = column ^ (1 << y);
            dia = dia ^ 1 << (x - y + n - 1);
            cdia = cdia ^ 1 << (x + y - 2);
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int column = 0, dia = 0, cdia = 0;
        vector<vector<string> > ans;
        vector<int> tuple(0);
        solve(column, dia, cdia, 1, n, tuple, ans);
        return ans;
    }
};



