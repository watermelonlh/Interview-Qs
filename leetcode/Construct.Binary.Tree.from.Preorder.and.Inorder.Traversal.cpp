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
    TreeNode *build(vector<int> &preorder, int l1, int r1, vector<int> &inorder, int l2, int r2)
    {
        if (l1 == r1) return NULL;
        TreeNode *now = new TreeNode(preorder[l1]);
        for (int i = l2; i < r2; i++)
        {
            if (inorder[i] == preorder[l1])
            {
                int lc = i - l2, rc = r2 - i - 1;
                now->left = build(preorder, l1 + 1, l1 + 1 + lc, inorder, l2, i);
                now->right = build(preorder, r1 - rc, r1, inorder, i + 1, r2);
            }
        }
        return now;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
