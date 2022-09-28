/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head;
        int sz = 0;
        while (cur) {
            cur = cur->next;
            sz++;
        }
        if (sz == n) return head->next;
        else cur = head;
        for (int i=0; i<sz-n-1; i++) cur = cur->next;
        if (cur->next) cur->next = cur->next->next;
        return head;
    }
};