/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *build(ListNode *head, ListNode *tail)
    {
        if (head == tail) return NULL;
        ListNode *node1 = head, *node2 = head;
        while (node2 != tail)
        {
            node2 = node2->next;
            if (node2 == tail) break;
            node2 = node2->next;
            node1 = node1->next;
        }
        TreeNode *now = new TreeNode(node1->val);
        now->left = build(head, node1);
        now->right = build(node1->next, tail);
        return now;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return build(head, NULL);
    }
};
