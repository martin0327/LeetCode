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
    int n;
    vector<int> a;
    Solution(ListNode* head) {
        while (true) {
            a.push_back(head->val);
            if (head->next) head = head->next;
            else break;
        }
        n = a.size(); 
    }
    
    int getRandom() {
        auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
        mt19937 mt(seed);
        int x = mt()%n;
        return a[x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */