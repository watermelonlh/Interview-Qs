class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int la = a.size();
        int lb = b.size();
        int c = 0;
        string ans = "";
        for (int i = 0; i < la || i < lb || c; i++)
        {
            int na = 0, nb = 0;
            if (i < la) na = a[la - 1 - i] - '0';
            if (i < lb) nb = b[lb - 1 - i] - '0';
            c = na + nb + c;
            ans = (c & 1) ? "1" + ans : "0" + ans;
            c /= 2;
        }
        return ans;
    }
};
