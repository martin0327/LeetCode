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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<int> a;
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }
        int n = a.size();
        int q = n / k, r = n % k;
        vector<ListNode*> ans(k);
        int idx = 0;
        for (int i=0; i<k; i++) {
            int m = q + (i < r);
            if (m == 0) continue;
            vector<int> b(m);
            for (int j=0; j<m; j++) {
                b[j] = a[idx++];
            }
            ans[i] = new ListNode();
            auto v = ans[i];
            for (int j=0; j<m; j++) {
                v->val = b[j];
                if (j+1 < m) {
                    v->next = new ListNode();
                    v = v->next;
                }
            }            
        }
        return ans;
    }
};