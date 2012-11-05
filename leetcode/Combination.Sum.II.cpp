class Solution {
public:
    void generate(vector<int> &num, int p, int target, vector<int> &tuple, vector<vector<int> > &ans)
    {
        if (target == 0)
        {
            ans.push_back(tuple);
            return;
        }
        for (int i = p; i < num.size(); i++)
        {
            if (num[i] > target) break;
            if (i > p && num[i] == num[i - 1]) continue;
            tuple.push_back(num[i]);
            generate(num, i + 1, target - num[i], tuple, ans);
            tuple.pop_back();
        }
        
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> tuple;
        sort(num.begin(), num.end());
        generate(num, 0, target, tuple, ans);
        return ans;
    }
};
