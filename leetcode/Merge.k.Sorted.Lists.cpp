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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = lists.size();
        ListNode *head = NULL, *tail = NULL;
        while (1)
        {
            int k = -1;
            for (int i = 0; i < n; i++)
                if (lists[i]) 
                {
                    if (k == -1 || lists[i]->val < lists[k]->val)
                        k = i;
                }
            if (k == -1) break;
            if (head)
            {
                tail->next = lists[k];
                tail = tail->next;
            } else
            {
                head = tail = lists[k];
            }
            lists[k] = lists[k]->next;
        }
        return head;
    }
};
