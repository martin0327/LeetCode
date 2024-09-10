using vi = vector<int>;
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vi a;
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }
        int n = a.size();
        vi b;
        for (int i=1; i<n; i++) {
            b.push_back(__gcd(a[i],a[i-1]));
        }
        vi c;
        for (int i=0; i<n; i++) {
            c.push_back(a[i]);
            if (i < b.size()) c.push_back(b[i]);
        }
        int m = c.size();
        ListNode *ans = new ListNode(c[0]);
        auto cur = ans;
        for (int i=1; i<m; i++) {
            cur->next = new ListNode(c[i]);
            if (i+1<m) cur = cur->next;
        }
        return ans;
    }
};