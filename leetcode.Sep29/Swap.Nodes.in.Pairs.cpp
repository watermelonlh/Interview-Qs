/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return NULL;
        ListNode *pre = NULL, *left = head, *right = left->next, *next = NULL;
        if (!right) return head;
        while (right)
        {
            next = right->next;
            right->next = left;
            left->next = next;
            if (pre) pre->next = right;
            else head = right;
            pre = left;
            left = next;
            if (left) right = left->next; else right = NULL;
        }
        return head;
    }
};
