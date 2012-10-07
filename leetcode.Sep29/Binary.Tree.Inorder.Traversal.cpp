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
    void inorder(vector<int> &ans, TreeNode *root)
    {
        if (!root) return;
        inorder(ans, root->left);
        ans.push_back(root->val);
        inorder(ans, root->right);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        inorder(ans, root);
        return ans;
    }
};

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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        if (!root) return ans;
        stack<pair<TreeNode *, bool> > s;
        s.push(pair<TreeNode *, bool>(root, false));
        while (!s.empty())
        {
            pair<TreeNode *, bool> now = s.top();
            s.pop();
            if (now.second)
            {
                ans.push_back(now.first->val);
            } else
            {
                now.second = true;
                if (now.first->right) s.push(pair<TreeNode *, bool>(now.first->right, false));
                s.push(now);
                if (now.first->left) s.push(pair<TreeNode *, bool>(now.first->left, false));
            }
        }
        return ans;
    }
};
