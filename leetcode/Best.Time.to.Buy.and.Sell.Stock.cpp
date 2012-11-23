class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0) return 0;
        int minPrice = prices[0];
        int N = prices.size();
        int ans = 0;
        for (int i = 1; i < N; i++)
        {
            if (minPrice > prices[i])
            {
                minPrice = prices[i];
            }
            ans = max(ans, prices[i] - minPrice);
        }
        return ans;
    }
};
