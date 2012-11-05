class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string S = "#";
        for (int i = 0; i < s.size(); i++)
            S = S + s[i] + "#";
            
        int len = S.size();
        vector<int> l(len, 0);
        int center = 0, farest = 0;
        for (int i = 1; i < len; i++)
        {
            if (i > farest || l[center - (i - center)] + i >= farest)
            {
                if (i > farest) l[i] = 0; 
                else l[i] = farest - i;
                while (i + l[i] + 1< len && i - l[i] - 1>= 0 && S[i + l[i] + 1] == S[i - l[i] - 1]) l[i]++;
                farest = i + l[i];
                center = i;
            } else
            {
                l[i] = l[center - (i - center)];
            }
        }
        int k = 0;
        for (int i = 0; i < len; i++)
        {
            if (l[i] > l[k]) k = i;
        }
        return s.substr(k / 2 - l[k] / 2, l[k]);
    }
};
