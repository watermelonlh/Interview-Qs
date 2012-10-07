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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *pre, *node1 = head, *node2 = head;
        if (head == NULL) return NULL;
        int n = 0;
        while (node1) n++, node2 = node1, node1 = node1->next;
        k = k % n;
        if (k == 0) return head;
        node1 = head;
        for (int i = 0; i < n - k; i++)
        {
            pre = node1;
            node1 = node1->next;
        }
        node2->next = head;
        pre->next = NULL;
        head = node1;
        return head;
    }
};
