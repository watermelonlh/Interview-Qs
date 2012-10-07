class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int c = 1;
        int l = digits.size();
        while (c && l > 0)
        {
            c += digits[l - 1];
            digits[l - 1] = c % 10;
            c /= 10;
            l--;
        }
        if (c)
        {
            digits.insert(digits.begin(), c);
        }
        return digits;
    }
};
