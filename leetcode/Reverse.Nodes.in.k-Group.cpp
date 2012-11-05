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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *leftPre = NULL, *left = head, *right, *rightNext;
        if (k == 1) return head;
        while (left)
        {
            right = left;
            for (int i = 0; i < k - 1 && right; i++) right = right->next;
            if (!right) break;
            rightNext = right->next;
            ListNode *now = left, *pre = leftPre, *next;
            while (now != rightNext)
            {
                next = now->next;
                now->next = pre;
                pre = now;
                now = next;
            }
            left->next = rightNext;
            if (leftPre) leftPre->next = right;
            else head = right;
            leftPre = left;
            left = rightNext;
        }
        return head;
    }
};
