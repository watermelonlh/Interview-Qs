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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *pre = NULL, *node1 = head, *node2 = head;
        for (int i = 0; i < n; i++) node2 = node2->next;
        while (node2)
        {
            pre = node1;
            node1 = node1->next;
            node2 = node2->next;
        }
        if (pre) 
        {
            pre->next = node1->next;
            delete node1;
        } else
        {
            head = head->next;
            delete node1;
        }
        return head;
    }
};
