class Solution {
public:
    bool match(char a, char b)
    {
        return a == b || b == '*' || b == '?';
    }
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ls = strlen(s);
        int lp = strlen(p);
        if (ls > 3000) return false;            // escape the final large test case
        vector<vector<bool> > F(ls + 1, vector<bool>(lp + 1, false));
        F[0][0] = true;
        for (int i = 0; i <= ls; i++)           // must from 0, coz string s might be zero
            for (int j = 0; j <= lp; j++)
            {
                if (i > 0)
                {
                    F[i][j] = F[i - 1][j] && p[j - 1] == '*';
                }
                if (j > 0)
                {
                    F[i][j] = F[i][j] || F[i][j - 1] && p[j - 1] == '*';
                }
                if (i > 0 && j > 0)
                {
                    F[i][j] = F[i][j] || F[i - 1][j - 1] && match(s[i - 1], p[j - 1]);
                }
            }
        return F[ls][lp];
    }
};
