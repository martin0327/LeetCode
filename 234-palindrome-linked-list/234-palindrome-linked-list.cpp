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
    bool isPalindrome(ListNode* head) {
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }
        int n = a.size();
        bool ret = true;
        for (int i=0; i<n; i++) {
            if (a[i] != a[n-1-i]) ret = false;
        }
        return ret;
    }
};