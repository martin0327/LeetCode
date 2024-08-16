using vi = vector<int>;
class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int n = a.size(), inf = 1e9;
        vi lo = {0}, hi = {0};
        for (auto v : a) {
            lo.push_back(v.front());
            hi.push_back(v.back());
        }
        vi min_pre(n+1,inf), min_suf(n+2,inf);
        vi max_pre(n+1,-inf), max_suf(n+2,-inf);
        for (int i=1; i<=n; i++) {
            min_pre[i] = min(min_pre[i-1], lo[i]);
            max_pre[i] = max(max_pre[i-1], hi[i]);
        }
        for (int i=n; i>=1; i--) {
            min_suf[i] = min(min_suf[i+1], lo[i]);
            max_suf[i] = max(max_suf[i+1], hi[i]);
        }
        int ans = -inf;
        for (int i=1; i<=n; i++) {
            int mx = max(max_pre[i-1], max_suf[i+1]);
            int mn = min(min_pre[i-1], min_suf[i+1]);
            ans = max(ans, mx - lo[i]);
            ans = max(ans, hi[i] - mn);
        }
        
        return ans;
    }
};