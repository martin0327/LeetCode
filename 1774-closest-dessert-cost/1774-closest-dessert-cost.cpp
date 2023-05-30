class Solution {
public:
    int closestCost(vector<int>& a, vector<int>& b, int t) {
        int n = a.size(), m = b.size();
        for (int i=0; i<m; i++) b.push_back(b[i]);
        m = b.size();
        set<int> c;
        for (int mask=0; mask<(1<<m); mask++) {
            int s = 0;
            for (int i=0; i<m; i++) {
                if (mask>>i&1) s += b[i];
            }
            c.insert(s);
        }
        int d = 1e9;
        int ans = 1e9;
        for (auto x : a) {
            auto it = c.lower_bound(t-x);
            if (it != c.end()) {
                int y = x + *it;
                if (abs(y-t) < d) {
                    d = abs(y-t);
                    ans = y; 
                }
                else if (abs(y-t) == d) {
                    ans = min(ans, y);
                }
            }
            if (it != c.begin()) {
                int y = x + *prev(it);
                if (abs(y-t) < d) {
                    d = abs(y-t);
                    ans = y; 
                }
                else if (abs(y-t) == d) {
                    ans = min(ans, y);
                }
            }
        }
        return ans;
    }
};