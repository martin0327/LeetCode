using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vp = vector<pii>;
const int sz = 18, inf = 2e9;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& a, int mxd, vector<vector<int>>& qr) {
        vp b(n);
        for (int i=0; i<n; i++) {
            b[i] = {a[i],i};
        }
        sort(b.begin(), b.end());
        vi mp(n);
        for (int i=0; i<n; i++) {
            mp[b[i].second] = i;
        }
        vvi sp(sz, vi(n));
        for (int i=0; i<n; i++) {
            auto [x,j] = b[i];
            pii tg = {x+mxd,inf};
            auto it = upper_bound(b.begin(), b.end(), tg);
            sp[0][i] = it - b.begin() - 1;
        }
        for (int j=1; j<sz; j++) {
            for (int i=0; i<n; i++) {
                auto ni = sp[j-1][i];
                sp[j][i] = sp[j-1][ni];
            }
        }
        vector<int> ans;
        for (auto &uv : qr) {
            int u = uv[0], v = uv[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            u = mp[u], v = mp[v];
            if (u > v) swap(u,v);
            int lo = 1, hi = n, res = -1;
            while (lo <= hi) {
                int mid = (lo+hi)/2;
                auto x = u;
                for (int i=0; i<sz; i++) {
                    if (mid>>i&1) {
                        x = sp[i][x];
                    }
                }
                if (x >= v) {
                    res = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};