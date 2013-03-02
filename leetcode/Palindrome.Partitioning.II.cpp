class Solution {
public:
    
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if (len == 0) return 0;
        
        vector<vector<bool> > F(len, vector<bool>(len, false));
        for (int i = 0; i < len; i++)
        {
            for (int p1 = i, p2 = i; p1 >= 0 && p2 < len && s[p1] == s[p2]; p1--, p2++)
            {
                F[p1][p2] = true;
            }
            for (int p1 = i, p2 = i + 1; p1 >= 0 && p2 < len && s[p1] == s[p2]; p1--, p2++)
            {
                F[p1][p2] = true;
            }
        }
                
        vector<int> G(len, -1);
        for (int i = 0; i < len; i++)
            for (int j = 0; j <= i; j++)
            {
                if (!F[j][i]) continue;
                if (j == 0) 
                {
                    G[i] = 0;
                    continue;
                }
                if (G[j - 1] == -1) continue;
                if (G[i] == -1 || G[j - 1] + 1 < G[i]) G[i] = G[j - 1] + 1;
            }
        return G[len - 1];
    }
};
