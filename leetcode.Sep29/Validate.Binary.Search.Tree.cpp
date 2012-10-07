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
    bool inOrder(TreeNode *root, int &val)
    {
        if (root == NULL) return true;
        if (!inOrder(root->left, val)) return false;
        if (root->val <= val) return false;
        val = root->val;
        if (!inOrder(root->right, val)) return false;
        return true;
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int val = INT_MIN;
        return inOrder(root, val);
    }
};


// check the in order travel whether in increasing order or not
