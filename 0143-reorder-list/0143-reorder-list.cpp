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
    void reorderList(ListNode* head) {
        if (!head->next) return;
        deque<ListNode*> dq;
        while (head->next) {
            dq.push_back(head);
            head = head->next;
        }
        dq.push_back(head);
        ListNode* prev = nullptr;        
        while (dq.size()>1) {
            ListNode* a = dq.front();
            dq.pop_front();
            ListNode* b = dq.back();
            dq.pop_back();
            if (prev) prev->next = a;
            a->next = b;
            prev = b;
        }
        if (dq.size()) {
            ListNode* a = dq.front();
            dq.pop_front();
            prev->next = a;
            a->next = nullptr;
        }
        else {
            prev->next = nullptr;
        }
    }
};