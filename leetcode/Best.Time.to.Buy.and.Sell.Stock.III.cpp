class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = prices.size();
        if (N < 2) return 0;
        int ans = 0;
        vector<int> right(N, 0);
        int maxPrices = prices[N - 1];
        for (int i = N - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], maxPrices - prices[i]);
            maxPrices = max(maxPrices, prices[i]);
            ans = max(right[i], ans);
        }
        int minPrices = prices[0];
        for (int i = 1; i <= N - 2; i++)
        {
            int sum = prices[i] - minPrices + right[i + 1];
            minPrices = min(minPrices, prices[i]);
            ans = max(sum, ans);
        }
        return ans;
    }
};

