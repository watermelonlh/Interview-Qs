class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        int cnt = 0;
        int l = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                cnt++;
            } else 
            {
                cnt--;
                if (cnt == 0) 
                    if (i - l + 1 > ans) ans = i - l + 1;
                if (cnt < 0) l = i + 1, cnt = 0;
            }
        }
        cnt = 0;
        l = s.size() - 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
            {
                cnt++;
            } else
            {
                cnt--;
                if (cnt == 0) 
                    if (l - i + 1> ans) ans = l - i + 1;
                if (cnt < 0) l = i - 1, cnt = 0;
            }
        }
        return ans;
    }
};
