class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        vector<ListNode*> a;
        
        while (head) {
            a.push_back(head);
            head = head->next;
        }
        
        k %= a.size();
        
        vector<ListNode*> b;
        for (int i=0; i<k; i++) {
            b.push_back(a.back());
            a.pop_back();
        }
        reverse(b.begin(), b.end());
        head = a.front();
        while (b.size()) {
            ListNode* temp = b.back();
            b.pop_back();
            temp->next = head;
            head = temp;
        }
        a.back()->next = nullptr;
        return head;
    }
};