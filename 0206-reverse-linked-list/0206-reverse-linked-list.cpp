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
    ListNode* reverseList(ListNode* u) {
        if (!u) return u;
        while (u) {
            a.push_back(u->val);
            u = u->next;
        }
        reverse(a.begin(), a.end());
        ListNode* ret = new ListNode();
        u = ret;
        int sz = a.size();
        for (int i=0; i<sz; i++) {
            u->val = a[i];
            if (i+1 < sz) {
                u->next = new ListNode();
                u = u->next;
            }
        }
        return ret;        
    }
};