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
    TreeNode *build(vector<int> &inorder, int l1, int r1, vector<int> &postorder, int l2, int r2)
    {
        if (l1 == r1) return NULL;
        TreeNode *now = new TreeNode(postorder[r2 - 1]);
        for (int i = l1; i < r1; i++)
        {
            if (postorder[r2 - 1] == inorder[i])
            {
                int lc = i - l1, rc = r1 - i - 1;
                now->left = build(inorder, l1, i, postorder, l2, l2 + lc);
                now->right = build(inorder, i + 1, r1, postorder, l2 + lc, r2 - 1);
            }
        }
        return now;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
