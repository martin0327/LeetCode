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
    vector<int> a;
    vector<int> b;
    ListNode* partition(ListNode* head, int x) {
        ListNode* ret = head;
        while (head) {
            int y = head->val;
            if (y < x) a.push_back(y);
            else b.push_back(y);
            head = head->next;
        }
        head = ret;
        for (auto x : a) {
            head->val = x;
            head = head->next;
        }
        for (auto x : b) {
            head->val = x;
            head = head->next;
        }
        return ret;
    }
};