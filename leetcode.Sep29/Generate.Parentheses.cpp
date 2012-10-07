class Solution {
public:
    void generate(string now, int left, int right, vector<string> &ans)
    {
        if (!left && !right)
        {
            ans.push_back(now);
            return;
        }
        if (left < right) generate(now + ")", left, right - 1, ans);
        if (left > 0) generate(now + "(", left - 1, right, ans);
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        generate("", n, n, ans);
        return ans;
    }
};
