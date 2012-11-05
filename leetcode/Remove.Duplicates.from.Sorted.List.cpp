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
        ListNode *pre = NULL, *now = head;
        while (now)
        {
            ListNode *tmp;
            while (now->next && now->next->val == now->val) 
            {
                tmp = now->next;
                now->next = tmp->next;
                delete tmp;
            }
            pre = now;
            now = now->next;
        }
        return head;
    }
};
