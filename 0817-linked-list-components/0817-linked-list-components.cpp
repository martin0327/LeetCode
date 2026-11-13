class Solution {
public:
    int numComponents(ListNode* head, vector<int> &a) {
        vector<int> b;
        while (head) {
            b.push_back(head->val);
            head = head->next;
        }
        map<int,int> mp;
        int n = b.size(), m = a.size(), ans = 1;
        for (int i=0; i<n; i++) mp[b[i]] = i;
        sort(a.begin(), a.end(), [&] (int x, int y) {
            return mp[x] < mp[y];
        });
        for (int i=1; i<m; i++) {
            auto x = mp[a[i-1]];
            auto y = mp[a[i]];
            if (x+1 != y) ans++;
        }
        return ans;
    }
};