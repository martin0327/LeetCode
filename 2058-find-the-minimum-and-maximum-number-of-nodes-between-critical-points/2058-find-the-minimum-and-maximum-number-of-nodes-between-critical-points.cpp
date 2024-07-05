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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> a;
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }
        int n = a.size();
        vector<int> idx;
        for (int i=1; i+1<n; i++) {
            if ((long long) (a[i]-a[i-1]) * (a[i]-a[i+1]) > 0) idx.push_back(i);
        }
        if (idx.size() <= 1) return {-1,-1};
        
        int mx = idx.back() - idx.front();
        int mn = mx;
        for (int i=1; i<idx.size(); i++) {
            int t = idx[i] - idx[i-1];
            mn = min(mn, t);
        }
        return {mn,mx};
    }
};