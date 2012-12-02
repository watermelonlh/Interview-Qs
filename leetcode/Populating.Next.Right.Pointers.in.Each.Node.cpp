/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void getNext(TreeLinkNode *parent, TreeLinkNode *now)
    {
        if (!now) return;
        if (parent)
        {
            if (now == parent->left) now->next = parent->right;
            else now->next = (parent->next) ? parent->next->left : NULL;
        } else
        {
            now->next = NULL;
        }
        getNext(now, now->left);
        getNext(now, now->right);
    }
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return;
        getNext(NULL, root);
    }
};
