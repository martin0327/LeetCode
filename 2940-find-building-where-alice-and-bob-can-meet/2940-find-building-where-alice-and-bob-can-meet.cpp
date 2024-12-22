using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& a, vector<vector<int>>& qr) {
        ll n = a.size(), q = qr.size();
        map<ll,vi> mp;
        set<ll> ord;
        for (int i=0; i<n; i++) {
            mp[a[i]].push_back(i);
            ord.insert(-a[i]);
        }
        vector<tuple<ll,ll,ll,ll>> off(q);
        for (int i=0; i<q; i++) {
            ll u = qr[i][0], v = qr[i][1];
            ll lim = max(a[u],a[v]);
            off[i] = {lim, u, v, i};
            ord.insert(-lim);
        }
        sort(off.begin(),off.end());
        vector<int> ans(q,-1);
        set<int> s;
        for (auto lim : ord) {
            lim *= -1;
            while (off.size()) {
                auto [mx,u,v,idx] = off.back();
                if (mx==lim) {
                    off.pop_back();
                    ll t = max(u,v);
                    if (u > v) swap(u,v);
                    auto it = s.lower_bound(t);
                    if (u==v) ans[idx] = u;
                    else if (a[u] < a[v]) ans[idx] = v;
                    else if (it != s.end()) ans[idx] = *it;
                } else break;
            }
            for (auto x : mp[lim]) s.insert(x);
        }
        return ans;
    }
};