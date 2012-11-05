class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        bool mark[256];
        memset(mark, 0, sizeof(mark));
        for (int l = 0, r = 0; r < s.size(); )
        {
            while (r < s.size() && !mark[s[r]])
            {
                mark[s[r]] = true;
                r++;
            }
            if (r - l > ans)
            {
                ans = r - l;
            }
            mark[s[l++]] = false;
        }
        return ans;
    }
};
