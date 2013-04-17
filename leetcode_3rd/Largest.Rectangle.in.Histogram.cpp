class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> s;
        int N = height.size();
        if (!N) return 0;
        vector<int> left(N), right(N);
        s.push(0);
        left[0] = 0;
        for (int i = 1; i < N; i++)
        {
            while (!s.empty() && height[i] <= height[s.top()]) s.pop();
            left[i] = (s.empty()) ? 0 : s.top() + 1;
            s.push(i);
        }
        while (!s.empty()) s.pop();
        s.push(N - 1);
        right[N - 1] = N - 1;
        for (int i = N - 2; i >= 0; i--)
        {
            while (!s.empty() && height[i] <= height[s.top()]) s.pop();
            right[i] = (s.empty()) ? N - 1 : s.top() - 1;
            s.push(i);
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans = max(ans, height[i] * (right[i] - left[i] + 1));
        }
        return ans;
    }
};
