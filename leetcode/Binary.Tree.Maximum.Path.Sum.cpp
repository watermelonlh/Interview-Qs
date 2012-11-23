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
    int calcTree(TreeNode *root, int &ans)
    {
        
        int F = 0;
        if (root == NULL) return F;
        
        int left, right;
        left = calcTree(root->left, ans);
        right = calcTree(root->right, ans);
        ans = max(ans, left + right + root->val);
        ans = max(ans, left + root->val);
        ans = max(ans, right + root->val);
        F = max(0, max(left, right)) + root->val;
        return F;
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        if (root)
        {
            ans = root->val;
            calcTree(root, ans);
        }
        return ans;
    }
};
