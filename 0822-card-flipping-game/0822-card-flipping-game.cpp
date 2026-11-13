const int inf = 2e9;
class Solution {
public:
    int flipgame(vector<int>& a, vector<int>& b) {
        int n = a.size();
        set<int> s;
        for (int i=0; i<n; i++) {
            if (a[i] == b[i]) s.insert(a[i]);
        }
        auto ans = inf;
        for (auto x : a) {
            if (s.count(x)) continue;
            ans = min(ans, x);
        }
        for (auto x : b) {
            if (s.count(x)) continue;
            ans = min(ans, x);
        }
        if (ans == inf) ans = 0;
        return ans;
    }
};