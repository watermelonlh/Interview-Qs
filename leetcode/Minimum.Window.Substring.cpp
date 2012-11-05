class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ls = S.size();
        int lt = T.size();
        int cnt[256];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < lt; i++)
            cnt[T[i]]++;
        int l = 0, r = 0, tot = 0;
        string ans = "";
        while (r < ls)
        {
            while (tot < lt && r < ls)
            {
                cnt[S[r]]--;
                if (cnt[S[r]] >= 0) tot++;
                r++;
            }
            if (tot < lt) break;
            while (1)
            {
                if (cnt[S[l]] + 1 <= 0)
                    cnt[S[l]]++;
                else break;
                l++;
            }
            if (r - l > 0 && (ans == "" || r - l < ans.size()))
                ans = S.substr(l, r - l);
            cnt[S[l]]++; 
            l++;
            tot--;
        }
        return ans;
    }
};
