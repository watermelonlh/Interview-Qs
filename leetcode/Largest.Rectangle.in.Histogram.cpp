class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> heights, indexes;
        int N = height.size();
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            int lastIndex = i;
            while (!heights.empty() && height[i] <= heights.top())
            {
                int sum = heights.top() * (i - indexes.top());    
                ans = max(sum, ans);
                lastIndex = indexes.top();
                indexes.pop();
                heights.pop();
                
            }
            heights.push(height[i]);
            indexes.push(lastIndex);
        }
        while (!heights.empty())
        {
            int sum = heights.top() * (N - indexes.top());
            ans = max(ans, sum);
            indexes.pop();
            heights.pop();
        }
        return ans;
    }
};



class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
        if (n == 0) return 0;
        vector<int> left(n, 0), right(n, 0);
        left[0] = 0;
        for (int i = 1; i < n; i++)
        {
            left[i] = i;
            while (left[i] > 0 && height[left[i] - 1] >= height[i]) left[i] = left[left[i] - 1];
        }
        right[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = i;
            while (right[i] < n - 1 && height[right[i] + 1] >= height[i]) right[i] = right[right[i] + 1];
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = (right[i] - left[i] + 1) * height[i];
            if (sum > ans) ans = sum;
        }
        return ans;
        
    }
};
