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
    ListNode* middleNode(ListNode* head) {
        if (!head->next) return head;
        int cnt = 1;
        ListNode* cur = head;
        while (cur->next) {
            cur = cur->next;
            cnt++;
        }
        cnt = cnt / 2 + 1;
        ListNode* ret = head;
        while (true) {
            ret = ret->next;
            cnt--;
            if (cnt==1) return ret;
        }
    }
};