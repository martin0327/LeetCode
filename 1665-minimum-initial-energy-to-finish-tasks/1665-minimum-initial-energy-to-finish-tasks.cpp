using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vp = vector<pii>;
const ll inf = 2e18;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& a) {
        vp b;
        for (auto &v : a) {
            int x = v[0], y = v[1];
            b.push_back({x,y-x});
        }
        sort(b.begin(), b.end(), [&] (pii p1, pii p2) {
            auto [x1,y1] = p1;
            auto [x2,y2] = p2;
            return x1 + max(y1,x2+y2) < x2 + max(y2,x1+y1);
        });

        ll lo = 0, hi = 1e12, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            ll rem = mid;
            bool ok = true;
            for (auto &[x,y] : b) {
                if (rem >= x+y) {
                    rem -= x;
                }
                else ok = false;
            }
            if (ok) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};