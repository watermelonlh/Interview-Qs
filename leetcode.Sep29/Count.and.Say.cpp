class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string s = "1";
        for (int i = 2; i <= n; i++)
        {
            int count = 0, k = 0;
            string ns = "";
            for (int i = 0; i <= s.size(); i++)
            {
                if (i < s.size() && s[k] == s[i])
                {
                    count++;
                } else
                {
                    stringstream sin;
                    sin << count;
                    ns = ns + sin.str() + s[k];
                    count = 1;
                    k = i;
                }
            }
            s = ns;
        }
        return s;
    }
};
