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
    int depth(TreeNode *root, bool &ans)
    {
        if (!root) return 0;
        int lc = depth(root->left, ans);
        int rc = depth(root->right, ans);
        if (abs(lc - rc) > 1) ans = false;
        return max(lc, rc) + 1;
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool ans = true;
        depth(root, ans);
        return ans;
    }
};
