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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ret = head;
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }
        int n = a.size();
        reverse(a.begin() + (left-1), a.begin() + right);
        head = ret;
        int idx = 0;
        while (head) {
            head->val = a[idx++];
            head = head->next;
        }
        return ret;
    }
};