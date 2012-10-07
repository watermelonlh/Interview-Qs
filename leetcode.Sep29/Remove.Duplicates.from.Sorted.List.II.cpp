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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *pre = NULL, *now = head, *next;
        while (now)
        {
            bool dup = false;
            ListNode *tmp;
            while (now->next && now->next->val == now->val)
            {
                tmp = now->next;
                now->next = tmp->next;
                delete tmp;
                dup = true;
            }
            next = now->next;
            if (dup)
            {
                if (pre) 
                {
                    pre->next = now->next;
                    delete now;
                } else
                {
                    head = now->next;
                    delete now;
                }
            } else
            {
                pre = now;
            }
            now = next;
        }
        return head;
    }
};
