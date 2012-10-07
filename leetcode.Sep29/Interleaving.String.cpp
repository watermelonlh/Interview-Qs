class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        if (l1 + l2 != l3) return false;
        if (!l1) return s2 == s3;
        if (!l2) return s1 == s3;
        vector<vector<bool> > F(l1 + 1, vector<bool>(l2 + 1, false));
        
        F[0][0] = true;
        for (int i = 0; i <= l1; i++)
            for (int j = 0; j <= l2; j++)
            {
                if (!i && !j) continue;
                if (i > 0) F[i][j] = F[i][j] || F[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                if (j > 0) F[i][j] = F[i][j] || F[i][j - 1] && s2[j - 1] == s3[i + j - 1];
            }
        return F[l1][l2];
    }
};
