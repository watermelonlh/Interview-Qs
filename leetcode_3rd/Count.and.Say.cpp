class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans = "1";
        for (int i = 2; i <= n; i++)
        {
            string next = "";
            int c = 0;
            char ch = '.';
            for (int k = 0; k <= ans.size(); k++)
            {
                if (ans[k] != ch || k == ans.size())
                {
                    if (c > 0)
                    {
                        stringstream ins;
                        ins << c << ch;
                        next = next + ins.str();
                    }
                    if (k < ans.size())
                    {
                        c = 1;
                        ch = ans[k];
                    }
                } else c++;
            }
            ans = next;
        }
        return ans;
    }
};
