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
ListNode* jump(ListNode* head, bool odd) {
    if (!head->next) {
        if (odd) return head;
    }
    else if (!head->next->next) {
        if (odd) return head;
    }
    ListNode* temp = head->next;
    if (head->next->next) head->next = head->next->next;
    else head->next = nullptr;
    return jump(temp, !odd);
}

class Solution {
public:
    
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* even_first = head->next;
        ListNode* odd_last = jump(head, true);
        odd_last->next = even_first;
        return head;        
    }
};