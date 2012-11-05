class Solution {
public:
    bool match(char a, char b)
    {
        return a == b || b == '.';
    }
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int ls = strlen(s);
        int lp = strlen(p);
        vector<vector<bool> > F(ls + 1, vector<bool>(lp + 1, false));
        
        F[0][0] = true;
        for (int i = 0; i <= ls; i++)
            for (int j = 0; j <= lp; j++)
            {
                if (!i && !j) continue;
                if (j > 1)
                {
                    if (F[i][j - 2] && p[j - 1] == '*') F[i][j] = true;
                }
                if (i > 0 && j > 0)
                {
                    if (F[i - 1][j - 1] && match(s[i - 1], p[j - 1])) F[i][j] = true;
                }
                if (i > 0 && j > 1)
                {
                    if (F[i - 1][j] && p[j - 1] == '*' && match(s[i - 1], p[j - 2])) F[i][j] = true;
                }
            }
        return F[ls][lp];
    }
};
