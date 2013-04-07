class Solution {
public:
    int getCount(unordered_set<int> &hash, int x, int step)
    {
        int res = 0;
        while (1)
        {
            x += step;
            if (!hash.count(x)) return res;
            hash.erase(x);
            res++;
        }
    }
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> hash;
        for (int i = 0; i < num.size(); i++)
            hash.insert(num[i]);
        
        int ans = 0;
        for (int i = 0; i < num.size(); i++)
        {
            if (hash.count(num[i]))
            {
                hash.erase(num[i]);
                ans = max(ans, getCount(hash, num[i], -1) + 1 + getCount(hash, num[i], 1));
            }
        }
            
        return ans;
    }
};
