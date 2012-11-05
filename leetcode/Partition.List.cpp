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
        int n = 0, l = 0, r = 0;
        ListNode *hl = NULL, *hr = NULL, *left = NULL, *right = NULL, *now = head;
        while (now)
        {
            if (now->val < x)
            {
                if (left) 
                {
                    left->next = new ListNode(now->val);
                    left = left->next;
                } else
                {
                    hl = left = new ListNode(now->val);
                }
            } else
            {
                if (right)
                {
                    right->next = new ListNode(now->val);
                    right = right->next;
                } else
                {
                    hr = right = new ListNode(now->val);
                }
            } 
            now = now->next;
        }
        
        if (hl) 
        {
            left->next = hr;
            return hl;
        } else return hr;
    }
};
