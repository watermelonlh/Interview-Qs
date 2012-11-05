class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1 = word1.size();
        int l2 = word2.size();
        vector<vector<int> > F(l1 + 1, vector<int>(l2 + 1, -1));
        F[0][0] = 0;
        for (int i = 0; i <= l1; i++)
            for (int j = 0; j <= l2; j++)
            {
                if (!i && !j) continue;
                int opt;
                if (i && j && F[i - 1][j - 1] > -1)
                {
                    opt = F[i - 1][j - 1] + !(word1[i - 1] == word2[j - 1]);
                    if (F[i][j] == -1 || F[i][j] > opt)
                        F[i][j] = opt;
                }
                if (i && F[i - 1][j] > -1)
                {
                    opt = F[i - 1][j] + 1;
                    if (F[i][j] == -1 || F[i][j] > opt)
                        F[i][j] = opt;
                }
                if (j && F[i][j - 1] > - 1)
                {
                    opt = F[i][j - 1] + 1;
                    if (F[i][j] == -1 || F[i][j] > opt)
                        F[i][j] = opt;
                }
            }
        return F[l1][l2];
    }
};
