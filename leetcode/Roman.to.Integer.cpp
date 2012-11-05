class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int value[256];
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;
        int l = s.size();
        int ans = 0;
        for (int i = 0; i < l; i++)
        {
            int k = i;
            while (s[k] == s[i]) k++;
            if (value[s[k]] > value[s[i]])
            {
                ans += value[s[k]] - (k - i) * value[s[i]];
                i = k;
            } else
            {
                ans += (k - i) * value[s[i]];
                i = k - 1;
            }
        }
        return ans;
    }
};
