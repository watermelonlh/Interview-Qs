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
        ListNode *headLess = NULL, *tailLess = NULL, *headNotLess = NULL, *tailNotLess = NULL;
        ListNode *now = head;
        while (now)
        {
            if (now->val < x)
            {
                if (!headLess)
                {
                    headLess = tailLess = now;
                } else
                {
                    tailLess->next = now;
                    tailLess = now;
                }
            } else
            {
                if (!headNotLess)
                {
                    headNotLess = tailNotLess = now;
                } else
                {
                    tailNotLess->next = now;
                    tailNotLess = now;
                }
            }
            now = now->next;
        }
        if (!headNotLess) 
            return headLess;
        else if (!headLess) 
            return headNotLess;
        else {
            tailLess->next = headNotLess;
            tailNotLess->next = NULL;
            return headLess;
        }
    }
};
