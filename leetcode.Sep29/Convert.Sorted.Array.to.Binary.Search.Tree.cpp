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
    TreeNode *build(vector<int> &num, int l, int r)
    {
        if (l == r) return NULL;
        int mid = (l + r) / 2;
        TreeNode *now = new TreeNode(num[mid]);
        now->left = build(num, l, mid);
        now->right = build(num, mid + 1, r);
        return now;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return build(num, 0, num.size());
    }
};
