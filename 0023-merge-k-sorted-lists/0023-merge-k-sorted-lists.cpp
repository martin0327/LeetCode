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
    ListNode* mergeKLists(vector<ListNode*>& a) {
        if (a.size()==0) {
            return nullptr;
        }
        vector<int> b;
        for (auto node : a) {
            while (node) {
                b.push_back(node->val);
                node = node->next;
            }
        }
        if (b.size()==0) {
            return nullptr;
        }
        sort(b.begin(),b.end());
        int n = b.size();
        ListNode *ret = new ListNode(b[0]);
        auto cur = ret;
        for (int i=1; i<n; i++) {
            cur->next = new ListNode(b[i]);
            cur = cur->next;
        }
        return ret;
    }
};