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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        if (!root) return ans;
        
        vector<TreeNode *> que;
        int h = 0;
        que.push_back(root);
        while (h < que.size())
        {
            int t = que.size();
            ans.push_back(vector<int>(0));
            for (int i = h; i < t; i++)
            {
                ans.back().push_back(que[i]->val);
                if (que[i]->left) que.push_back(que[i]->left);
                if (que[i]->right) que.push_back(que[i]->right);
            }
            h = t;
        }
        return ans;
    }
};
