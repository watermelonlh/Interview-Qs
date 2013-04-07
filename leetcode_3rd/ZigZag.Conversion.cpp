class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows == 1) return s;
        vector<string> rows(nRows, "");
        for (int k = 0, step = 1, i = 0; i < s.size(); i++, k += step)
        {
            rows[k] += s[i];
            if (k + step == -1 || k + step == nRows) step = -step;
        }
        string ans = "";
        for (int k = 0; k < nRows; k++)
            ans += rows[k];
        return ans;
    }
};
