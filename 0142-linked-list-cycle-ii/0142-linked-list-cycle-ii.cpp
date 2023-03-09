/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      set<ListNode*> s;
      
      ListNode* node = head;
      while (node) {
        if (s.count(node)) return node;
        s.insert(node);
        node = node->next;        
      }
      
      return nullptr;
    }
};