class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function- 1
        string ans = "";
        int p = 1;
        for (int i = 1; i <= n; i++) 
        {
            p = p * i;
            ans = ans + char('0' + i);
        }
        for (int i = 0; i < n - 1; i++)
        {
            p /= n - i;
            int j = i;
            while (k > p)
            {
                j++;
                swap(ans[i], ans[j]);
                k -= p;
            }
        }
        return ans;
    }
};
