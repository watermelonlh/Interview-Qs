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
            if (now == parent->left && parent->right) 
            {
                now->next = parent->right;
            }
            else 
            {
                TreeLinkNode *parentNext = parent->next;
                now->next = NULL;
                while (parentNext)
                {
                    if (parentNext->left)
                    {
                        now->next = parentNext->left;
                        break;
                    } else if (parentNext->right)
                    {
                        now->next = parentNext->right;
                        break;
                    }
                    parentNext = parentNext->next;
                }
            }
        } else
        {
            now->next = NULL;
        }
        getNext(now, now->right);
        getNext(now, now->left);
    }
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return;
        getNext(NULL, root);
    }
};
