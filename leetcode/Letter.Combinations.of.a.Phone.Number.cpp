class Solution {
public:
    void gen(string chr[], int p, string &digits, vector<string> &ans, string now)
    {
        if (p == digits.size())
        {
            ans.push_back(now);
            return;
        }
        if (chr[digits[p] - '0'].size() > 0)
        {
            for (int i = 0; i < chr[digits[p] - '0'].size(); i++)
            {
                gen(chr, p + 1, digits, ans, now + chr[digits[p] - '0'][i]);
            }
        } else
        {
            gen(chr, p + 1, digits, ans, now);
        }
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string chr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        gen(chr, 0, digits, ans, "");
        return ans;      
    }
};
