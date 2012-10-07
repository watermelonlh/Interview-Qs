class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int r = strlen(s) - 1;
        
        while (r >= 0 && s[r] == ' ') r--;
        int l = r;
        while (l >= 0 && s[l] != ' ') l--;
        return r - l;
    }
};
