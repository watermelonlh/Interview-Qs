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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<TreeNode *> que;
        if (!root) return ans;
        int h = 0, t = 1;
        int dep = 0;
        que.push_back(root);
        while (h < t)
        {
            int lastT = t;
            dep++;
            ans.push_back(vector<int>(0));
            for (int i = h; i < lastT; i++)
            {
                if (dep & 1)
                {
                    ans.back().push_back(que[i]->val);
                } else
                {
                    ans.back().push_back(que[lastT - 1 - (i - h)]->val);
                }
                if (que[i]->left)
                {
                    que.push_back(que[i]->left);       
                    t++;
                }
                if (que[i]->right)
                {
                    que.push_back(que[i]->right);
                    t++;
                }
            }
            h = lastT;
        }
        return ans;
    }
};
