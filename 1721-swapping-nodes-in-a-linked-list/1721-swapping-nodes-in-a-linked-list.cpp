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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* cur = head;
        vector<int> a;
        while (cur) {
            a.push_back(cur->val);
            cur = cur->next;            
        }
        
        int n = a.size();
        swap(a[k-1], a[n-k]);
        int idx = 0;
        cur = head;
        while (cur) {
            cur->val = a[idx];
            idx++;
            cur = cur->next;
        }
        return head;
    }
};