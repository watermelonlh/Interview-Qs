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
    bool compare(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 ^ !r2) return false;
        if (!r1 && !r2) return true;
        if (r1->val != r2->val) return false;
        if (!compare(r1->left, r2->right)) return false;
        if (!compare(r1->right, r2->left)) return false;
        return true;
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return compare(root, root);
    }
};
