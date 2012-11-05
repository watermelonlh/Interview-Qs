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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int c = 0;
        ListNode *head = NULL, *tail;
        while (l1 || l2 || c)
        {
            if (l1) 
            {
                c = c + l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                c = c + l2->val;
                l2 = l2->next;
            }
            if (head)
            {
                tail->next = new ListNode(c % 10);
                tail = tail->next;
            } else
            {
                head = tail = new ListNode(c % 10);
            }
            c /= 10;
        }
        return head;
    }
};
