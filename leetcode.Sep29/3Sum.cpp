class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> tuple(3);
        sort(num.begin(), num.end());
        int n = num.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && num[i] == num[i - 1]) continue;
            tuple[0] = num[i];
            int l = i + 1, r = n - 1;
            int goal = 0 - num[i];
            while (l < r)
            {
                while (l < r && num[l] + num[r] < goal) l++;
                while (l < r && num[l] + num[r] > goal) r--;
                if (l < r && num[l] + num[r] == goal)
                {
                    tuple[1] = num[l], tuple[2] = num[r];
                    ans.push_back(tuple);
                    l++, r--;
                    while (l < r && num[l - 1] == num[l]) l++;
                    while (l < r && num[r + 1] == num[r]) r--;
                }
            }
        }
        return ans;
    }
};
