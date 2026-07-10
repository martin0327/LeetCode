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
        sort(a.begin(), a.end());
        vvi sp(sz, vi(n));
        for (int i=0,j=0; i<n; i++) {
            while (j < n) {
                if (a[i]+mxd >= a[j]) j++;
                else break;
            }
            sp[0][i] = j-1;
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
            int res = -1, cur = 0;
            for (int j=sz-1; j>=0; j--) {
                if (sp[j][u] >= v) {
                    res = cur + (1<<j);
                }
                else {
                    cur += (1<<j);
                    u = sp[j][u];
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};