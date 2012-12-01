/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void gen(vector<TreeNode *> &ans, int l, int r)
    {
        vector<TreeNode *> lsub(0), rsub(0);    
        ans.clear();
        for (int x = l; x <= r; x++)
        {
            lsub.clear();
            rsub.clear();
            gen(lsub, l, x - 1);
            gen(rsub, x + 1, r);
            
            for (int i = 0; i <= lsub.size(); i++)
                for (int j = 0; j <= rsub.size(); j++)
                {
                    TreeNode *now = new TreeNode(x);
                    if (i > 0 && i == lsub.size()) continue;
                    if (j > 0 && j == rsub.size()) continue;
                    if (i < lsub.size()) now->left = lsub[i];
                    if (j < rsub.size()) now->right = rsub[j];
                    ans.push_back(now);
                }
            
        }
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> ans;
        if (n == 0) ans.push_back(NULL);
        if (n > 0) gen(ans, 1, n);
        return ans;
    }
};
