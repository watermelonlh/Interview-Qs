class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0) return 0;
        int ans = 0;
        int minIndex = 0;
        int N = prices.size();
        for (int i = 1; i <= N; i++)
        {
            if (i == N || prices[i] < prices[i - 1])
            {
                if (i > minIndex + 1)
                {
                    ans += prices[i - 1] - prices[minIndex];
                }
                minIndex = i;
            }
        }
        return ans;
    }
};


