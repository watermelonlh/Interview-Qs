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
    
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        if (!root) return ans;
        vector<TreeNode *> que;
        vector<int> dep;
        int h = 0;
        que.push_back(root);
        while (h < que.size())
        {
            int t = que.size();
            dep.push_back(t);
            for (int i = h; i < t; i++)
            {
                if (que[i]->left) que.push_back(que[i]->left); 
                if (que[i]->right) que.push_back(que[i]->right);
            }
            h = t;
        }
        int depth = dep.size();
        ans.resize(depth);
        for (int i = depth - 1; i >= 0; i--)
            for (int k = (i) ? dep[i - 1] : 0; k < dep[i]; k++)
            {
                ans[depth - 1 - i].push_back(que[k]->val);
            }
        return ans;
    }
};
