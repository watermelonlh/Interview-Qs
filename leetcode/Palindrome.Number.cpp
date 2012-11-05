class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        int y = 0, oX = x;
        while (x)
        {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y == oX;
    }
};
