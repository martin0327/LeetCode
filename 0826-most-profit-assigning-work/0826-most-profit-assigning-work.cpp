using pii = pair<int,int>;
using vp = vector<pii>;
class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n = d.size(), m = w.size();
        vp a(n);
        for (int i=0; i<n; i++) {
            a[i] = {d[i],p[i]};
        }
        sort(a.rbegin(), a.rend());
        sort(w.begin(), w.end());
        int ans = 0;
        int mx = 0;
        for (auto x : w) {
            while (a.size()) {
                auto [d,p] = a.back();
                if (d <= x) {
                    a.pop_back();
                    mx = max(mx, p);
                }
                else break;
            }
            ans += mx;
        }
        return ans;
    }
};