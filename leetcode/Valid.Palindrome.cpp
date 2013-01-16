class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            while (l < r && !isalpha(s[l]) && !isdigit(s[l])) l++;
            while (l < r && !isalpha(s[r]) && !isdigit(s[r])) r--;
            if (l < r)
            {
                if (tolower(s[l]) != tolower(s[r])) return false;
                l++, r--;
            }
        }
        return true;
    }
};
