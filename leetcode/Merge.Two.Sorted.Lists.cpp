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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head = NULL, *tail = NULL;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                if (head) 
                {
                    tail->next = l1;
                    tail = tail->next;
                } else
                {
                    head = tail = l1;
                }
                l1 = l1->next;
            } else
            {
                if (head)
                {
                    tail->next = l2;
                    tail = tail->next;
                } else
                {
                    head = tail = l2;
                }
                l2 = l2->next;
            }
        }
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        return head;
    }
};
