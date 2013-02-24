class Solution {
public:
    int getCount(unordered_set<int> &hash, int x, int step)
    {
        int count = 0;
        while (hash.count(x))
        {
            count++;
            hash.erase(x);
            x += step;
        }
        return count;
    }
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> hash;
        int N = num.size();
        vector<int> count(N, 1);
        for (int i = 0; i < N; i++)
            hash.insert(num[i]);
            
        int ans = 0;
        for (int i = 0; i < N; i++)
            ans = max(getCount(hash, num[i], -1) + getCount(hash, num[i] + 1, 1), ans);
        return ans;
    }
};
