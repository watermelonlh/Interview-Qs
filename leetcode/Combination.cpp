class Solution {
public:
    void generate(vector<int> &num, int target, int p, vector<int> &tuple, vector<vector<int> > &ans)
    {
        if (target == 0)
        {
            ans.push_back(tuple);
            return;
        }
        
        for (int i = p; i < num.size(); i++)
        {
            if (target < num[i]) break;
            tuple.push_back(num[i]);
            generate(num, target - num[i], i, tuple, ans);
            tuple.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> tuple;
        sort(candidates.begin(), candidates.end());
        generate(candidates, target, 0, tuple, ans);
        return ans;
    }
};
