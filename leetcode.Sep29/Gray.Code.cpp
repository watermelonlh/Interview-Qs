class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        for (int i = 0; i < 1 << n; i++)
        {
            ans.push_back(i ^ (i >> 1));
        }
        return ans;
    }
};
