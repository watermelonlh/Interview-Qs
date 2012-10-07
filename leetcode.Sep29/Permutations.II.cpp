class Solution {
public:
    void gen(vector<int> &num, vector<bool> &mark, vector<int> &tuple, vector<vector<int> > &ans)
    {
        if (tuple.size() == num.size())
        {
            ans.push_back(tuple);
            return;
        }
        
        int last = -1;
        for (int i = 0; i < num.size(); i++)
        {
            if (last > -1 && num[i] == num[last]) continue;
            if (mark[i]) continue;
            mark[i] = true;
            tuple.push_back(num[i]);
            gen(num, mark, tuple, ans);
            tuple.pop_back();
            mark[i] = false;
            last = i;
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = num.size();
        vector<vector<int> > ans;
        vector<bool> mark(N, false);
        vector<int> tuple;
        
        sort(num.begin(), num.end());
        gen(num, mark, tuple, ans);
        return ans;
    }
};
