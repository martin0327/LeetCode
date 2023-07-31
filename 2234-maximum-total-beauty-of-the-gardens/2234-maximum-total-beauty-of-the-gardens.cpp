using ll = long long;
using vi = vector<ll>;
void chmax(ll &x, ll y) {x = max(x,y);}

class Solution {
public:
    long long maximumBeauty(vector<int>& a, long long nf, int t, int full, int part) {
        sort(a.begin(), a.end());
        ll comp = 0;
        while (a.size()) {
            if (a.back() >= t) {
                comp++;
                a.pop_back();
            }
            else break;
        }
        ll n = a.size();
        ll ans = comp * full;
        if (!n) return ans;
        
        vi pre(n+1);
        for (int i=0; i<n; i++) pre[i+1] = pre[i] + a[i];
        for (int i=n; i>=0; i--) {
            if (i < n) {
                if (nf < t-a[i]) break;
                nf -= (t-a[i]);
                comp++;
            }
            ll lo = 0, hi = t-1, sup = 0;
            while (lo <= hi) {
                ll mid = (lo+hi)/2;
                auto it = lower_bound(a.begin(), a.begin()+i, mid);
                int r = it - a.begin();
                if (nf >= mid*r - pre[r]) {
                    sup = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            chmax(ans, comp*full + (i>0)*sup*part);
        }
        return ans;        
    }
};