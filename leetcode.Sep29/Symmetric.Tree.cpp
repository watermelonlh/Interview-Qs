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
    bool check(TreeNode *now1, TreeNode *now2)
    {
        if (!now1 ^ !now2) return false;
        if (!now1 && !now2) return true;
        if (now1->val != now2->val) return false;
        return check(now1->left, now2->right) && check(now1->right, now2->left);
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return check(root, root);
    }
};
