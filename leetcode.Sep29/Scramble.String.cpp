class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s1.size();
        if (len != s2.size()) return false;
        vector<vector<vector<bool> > > F(len + 1, vector<vector<bool> > (len, vector<bool>(len, false)));
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                if (s1[i] == s2[j]) F[1][i][j] = true;
        for (int l = 2; l <= len; l++)
            for (int i = 0; i < len - l + 1; i++)
                for (int j = 0; j < len - l + 1; j++)
                    for (int k = 1; k < l; k++)
                    {
                        F[l][i][j] = F[k][i][j] && F[l - k][i + k][j + k] || F[k][i][j + l - k] && F[l - k][i + k][j];
                        if (F[l][i][j]) break;
                    }
        return F[len][0][0];
    }
};
