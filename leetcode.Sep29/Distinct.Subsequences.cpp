class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lt = T.size(), ls = S.size();
        vector<vector<int> > F(lt + 1, vector<int>(ls + 1, 0));
        for (int j = 0; j <= ls; j++) F[0][j] = 1;
        for (int i = 1; i <= lt; i++)
            for (int j = 1; j <= ls; j++)
            {
                F[i][j] = F[i][j - 1];
                if (T[i - 1] == S[j - 1]) F[i][j] += F[i - 1][j - 1];
            }
        return F[lt][ls];
    }
};


