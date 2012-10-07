class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s == "") return 0;
        int l = s.size();
        vector<int> F(l + 1, 0);
        F[0] = 1;
        for (int i = 1; i <= l; i++)
        {
            if (s[i - 1] >= '1') F[i] = F[i - 1] + F[i];
            if (i > 1)
            {
                int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (num >= 10 && num <= 26) F[i] = F[i] + F[i - 2];
            }
        }
        return F[l];
    }
};
