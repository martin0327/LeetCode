class Solution {
public:
    int minSwaps(string s) {
        set<int> a,b;
        int n = s.size();
        for (int i=0; i<n; i++) {
            if (s[i] == '[') a.insert(i);
            else b.insert(i);
        }
        int ans = 0;
        while (a.size()) {
            int r = *b.begin();
            auto it = a.lower_bound(r);
            if (it == a.begin()) {
                int l = *a.rbegin();
                b.erase(r);
                a.erase(l);
                b.insert(l);
                a.insert(r);
                ans++;
            }
            else {
                b.erase(r);
                a.erase(--it);
            }
        }
        return ans;
    }
};