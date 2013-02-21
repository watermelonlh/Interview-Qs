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
    void pathToLeaf(TreeNode *root, int num, int &sum)
    {
        if (!root) return;
        num = num * 10 + root->val;
        if (!root->left && !root->right)
        {
            sum += num;
            return;
        }
        pathToLeaf(root->left, num, sum);
        pathToLeaf(root->right, num, sum);
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        pathToLeaf(root, 0, ans);
        return ans;
    }
};
