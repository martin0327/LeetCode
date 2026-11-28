using ll = long long;
using pii = pair<ll,ll>;
using vp = vector<pii>;
class Solution {
public:
    int carFleet(int tg, vector<int>& pos, vector<int>& spd) {
        int n = pos.size();
        vp a(n);
        for (int i=0; i<n; i++) {
            a[i] = {pos[i], spd[i]};
        }
        sort(a.rbegin(), a.rend());
        ll ans = 0;
        pii last = {0,1};
        for (auto [p,s] : a) {
            auto d = tg - p;
            auto [ld,ls] = last;
            if (d*ls > ld*s) {
                ans++;
                last = {d,s};
            }
        }
        return ans;
    }
};