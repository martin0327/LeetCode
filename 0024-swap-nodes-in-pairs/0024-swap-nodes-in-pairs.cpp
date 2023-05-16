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
    ListNode* swapPairs(ListNode* head) {
      stack<ListNode*> st;
      while (head) {
        st.push(head);
        head = head->next;
      }
      if (st.size()&1) {
        head = st.top();
        st.pop();
      }
      while (st.size()) {
        ListNode* a = st.top();
        st.pop();
        ListNode* b = st.top();
        st.pop();
        b->next = head;
        a->next = b;
        head = a;
      }      
      return head;
    }
};