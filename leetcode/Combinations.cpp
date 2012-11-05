class Solution {
public:
    void generate(vector<vector<int> > &ans, vector<int> &tuple, int now, int n, int k)
    {
        if (k == 0)
        {
            ans.push_back(tuple);
            return;
        }
        
        for (int i = now; i <= n; i++)
        {
            tuple.push_back(i);
            generate(ans, tuple, i + 1, n, k - 1);
            tuple.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> tuple(0);
        generate(ans, tuple, 1, n, k);
        return ans;
    }
};
