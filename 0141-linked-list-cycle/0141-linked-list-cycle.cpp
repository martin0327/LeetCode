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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        set<ListNode*> s;
        while (head) {
            if (s.count(head)) return true;
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};