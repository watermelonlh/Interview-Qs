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
    void getPath(TreeNode *root, int sum, vector<vector<int> > &ans, vector<int> &path)
    {
        if (root == NULL) return;
        if (!root->left && !root->right)
        {
            if (sum == root->val)
            {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }
        if (root->left)
        {
            path.push_back(root->val);
            getPath(root->left, sum - root->val, ans, path);
            path.pop_back();
        }
        if (root->right)
        {
            path.push_back(root->val);
            getPath(root->right, sum - root->val, ans, path);
            path.pop_back();
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans(0);
        vector<int> path(0);
        getPath(root, sum, ans, path);
        return ans;
    }
};
