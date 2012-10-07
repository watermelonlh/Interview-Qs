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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *pre = NULL, *leftPre, *left, *now = head, *next;
        int i = 0;
        while (now && i < n)
        {
            i++;
            next = now->next;
            if (i == m)
            {
                leftPre = pre;
                left = now;
            } else if (i == n)
            {
                now->next = pre;
                if (leftPre) leftPre->next = now;
                else head = now;
                left->next = next;
            } else if (i > m && i < n)
            {
                now->next = pre;
            }
            pre = now;
            now = next;
        }
        return head;
    }
};
