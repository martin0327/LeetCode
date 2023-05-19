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
    int pairSum(ListNode* head) {
      vector<int> a;
      a.push_back(head->val);
      while (head->next) {
        head = head->next;
        a.push_back(head->val);
      }
      int n = a.size();
      int ans = 0;
      for (int i=0; i<n; i++) {
        int temp = a[i] + a[n-1-i];
        ans = max(ans, temp);
      }
      return ans;
    }
};