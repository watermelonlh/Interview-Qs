class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<int, int> hash;
        int N = num.size();
        vector<bool> head(N, true);
        vector<int> next(N, -1);
        for (int i = 0; i < N; i++)
            hash[num[i]] = i + 1;
            
        for (int i = 0; i < N; i++)
        {
            if (hash[num[i] + 1] > 0)
            {
                next[i] = hash[num[i] + 1] - 1;
                head[next[i]] = false;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            int now = i;
            int step = 0;
            while (now >= 0)
            {
                step++;
                now = next[now];
            }
            ans = max(ans, step);
        }
        return ans;
    }
};
