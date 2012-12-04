class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int value[256];
        value['#'] = 0;
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;
        s = s + "#";
        int l = s.size();
        int ans = 0;
        for (int i = 0; i < l - 1; i++)
        {
            if (value[s[i]] < value[s[i + 1]])
                ans -= value[s[i]];
            else 
                ans += value[s[i]];
        }
        return ans;
    }
};
