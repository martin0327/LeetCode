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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> a;
        ListNode* cur = head;
        while (cur) {
            a.push_back(cur->val);
            cur = cur->next;
        }
        
        vector<int> b;
        for (auto x : a) {
            if (x==0) b.push_back(x);
            else b.back() += x;
        }
        b.pop_back();
        
        head = new ListNode();
        cur = head;
        for (int i=0; i<b.size(); i++) {
            cur->val = b[i];
            if (i<b.size()-1) {
                ListNode* temp = new ListNode();
                cur->next = temp;
                cur = temp;
            }
        }
        return head;
    }
};