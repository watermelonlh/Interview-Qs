class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int n = num.size();
        int ans = num[0] + num[1] + num[2];
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && num[i] == num[i - 1]) continue;
            int l = i + 1, r = n - 1;
            int goal = target - num[i];
            while (l < r)
            {
                while (l < r && num[l] + num[r] < goal) 
                {
                    if (abs(goal - num[l] - num[r]) < abs(ans - target))
                        ans = num[l] + num[r] + num[i];
                    l++;
                }
                while (l < r && num[l] + num[r] > goal)
                {
                    if (abs(goal - num[l] - num[r]) < abs(ans - target))
                        ans = num[l] + num[r] + num[i];
                    r--;
                }
                if (l < r && num[l] + num[r] == goal)
                {
                    ans = num[i] + num[l] + num[r];
                    l++, r--;
                    break;
                }
            }
            if (ans == target) break;
        }
        return ans;
    }
};
