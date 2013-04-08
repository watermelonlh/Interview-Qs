class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        vector<vector<bool> > palind(len, vector<bool>(len, false));
        for (int i = 0; i < len; i++)
        {
            int l = i, r = i;
            while (l >= 0 && r < len && s[l] == s[r])
            {
                palind[l][r] = true;
                l--, r++;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < len && s[l] == s[r])
            {
                palind[l][r] = true;
                l--, r++;
            }
        }
        if (palind[0][len - 1]) return 0;
        vector<int> F(len + 1, -1);
        F[0] = 0;
        for (int i = 1; i <= len; i++)
        {
            for (int k = 0; k < i; k++)
            {
                int l = k, r = i - 1;
                if (F[k] != -1 && palind[l][r])
                {
                    if (F[i] == -1 || F[k] + 1 < F[i])
                        F[i] = F[k] + 1;
                }
            }
        }
        return F[len] - 1;
    }
};
