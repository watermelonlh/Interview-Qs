class Solution {
public:
    bool isInteger(const char *s, int l, int r)
    {
        bool digit = false;
        for (int i = l; i < r; i++)
        {
            if (i == l && (s[i] == '-' || s[i] == '+')) continue;
            if (isdigit(s[i])) { digit = true; continue; }
            return false;
        }
        return digit;
    }
    bool isScitific(const char *s, int l, int r)
    {
        int e = l - 1;
        bool digit = false;
        bool dot = false;
        for (int i = l; i < r; i++)
        {
            if (i == e + 1 && (s[i] == '-' || s[i] == '+')) continue;
            if (isdigit(s[i])) { digit = true; continue; }
            if (s[i] == '.' && e == l - 1 && !dot) { dot = true; continue; }
            if (s[i] == 'e' && e == l - 1 && digit) { e = i; digit = false; continue; }
            return false;
        }
        return digit;
    }
    bool isFloat(const char *s, int l, int r)
    {
        bool dot = false;
        bool digit = false;
        for (int i = l; i < r; i++)
        {
            if (i == l && (s[i] == '-' || s[i] == '+')) continue;
            if (isdigit(s[i])) { digit = true; continue; }
            if (s[i] == '.' && !dot) { dot = true; continue; }
            return false;
        }
        return digit;
    }
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = strlen(s);
        while (l < r && s[l] == ' ') l++;
        while (l < r && s[r - 1] == ' ') r--;
        if (l >= r) return false;
        if (isInteger(s, l, r)) return true;
        if (isFloat(s, l, r)) return true;
        if (isScitific(s, l, r)) return true;
        return false;
    }
};
