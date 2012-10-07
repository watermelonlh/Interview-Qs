class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1 = num1.size();
        int l2 = num2.size();
        string ans = string(l1 + l2, '0');
        int c = 0;
        for (int i = l1 - 1; i >= 0; i--)
        {
            for (int j = l2 - 1; j >= 0; j--)
            {
                int k = l1 + l2 - 1 - (l1 - 1 - i) - (l2 - 1 - j);
                c += ans[k] - '0';
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                c += a * b;
                ans[k] = char('0' + c % 10);
                c /= 10;
            }
            int k = l1 + l2 - 1 - (l1 - 1 - i) - (l2 - 1) - 1;
            while (c)
            {
                c += ans[k] - '0';
                ans[k] = char('0' + c % 10);
                c /= 10;
                k--;
            }
        }
        int l = 0;
        while (l < ans.size() - 1 && ans[l] == '0') l++;
        ans.erase(0, l);
        return ans;
    }
};
