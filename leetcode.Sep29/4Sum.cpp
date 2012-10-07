class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        vector<vector<int> > ans;
        vector<int> tuple(4);
        int n = num.size();
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && num[i] == num[i - 1]) continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && num[j] == num[j - 1]) continue;
                int l = j + 1, r = n - 1;
                int goal = target - num[i] - num[j];
                tuple[0] = num[i], tuple[1] = num[j];
                while (l < r)
                {
                    while (l < r && num[l] + num[r] < goal) l++;
                    while (l < r && num[l] + num[r] > goal) r--;
                    if (l < r && num[l] + num[r] == goal)
                    {
                        tuple[2] = num[l], tuple[3] = num[r];
                        ans.push_back(tuple);
                        l++, r--;
                        while (l < r && num[l] == num[l - 1]) l++;
                        while (l < r && num[r] == num[r + 1]) r--;
                    }
                }
            }
        }
        return ans;
    }
};
