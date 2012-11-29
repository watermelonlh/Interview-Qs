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
    TreeNode *flat(TreeNode *now)
    {
        if (!now) return NULL;
        TreeNode *rend = flat(now->right);
        TreeNode *lend = flat(now->left);
        if (lend)
        {
            lend->right = now->right;
            now->right = now->left;
            now->left = NULL;
        }
        if (rend) return rend;
        else if (lend) return lend;
        else return now;
        
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flat(root);
        
    }
};