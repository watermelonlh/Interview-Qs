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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *h1 = NULL, *t1 = NULL, *h2 = NULL, *t2 = NULL;
        ListNode *now = head;
        while (now)
        {
            if (now->val < x)
            {
                if (!h1)
                {
                    h1 = t1 = now;
                } else
                {
                    t1->next = now;
                    t1 = now;
                }
            } else
            {
                if (!h2)
                {
                    h2 = t2 = now;
                } else
                {
                    t2->next = now;
                    t2 = now;
                }
            }
            now = now->next;
        }
        if (!h2) 
            return h1;
        else if (!h1) 
            return h2;
        else {
            t1->next = h2;
            t2->next = NULL;
            return h1;
        }
    }
};
