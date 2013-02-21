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
    int pathToLeaf(TreeNode *root, int num)
    {
        if (!root) return 0;
        num = num * 10 + root->val;
        if (!root->left && !root->right)
        {
            return num;
        }
        return pathToLeaf(root->left, num) + pathToLeaf(root->right, num);
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return pathToLeaf(root, 0);
    }
};
