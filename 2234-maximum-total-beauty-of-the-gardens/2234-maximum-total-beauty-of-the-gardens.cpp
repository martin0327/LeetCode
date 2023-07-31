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
        vi pre(n+1);
        ll ans = comp * full;
        if (a.empty()) return ans;
        for (int i=0; i<n; i++) pre[i+1] = pre[i] + a[i];
        {
            ll lo = 0, hi = t-1, sup = 0;
            while (lo <= hi) {
                ll mid = (lo+hi)/2;
                auto it = lower_bound(a.begin(), a.end(), mid);
                bool ok = false;
                if (it == a.begin()) ok = true;
                else {
                    int r = it - a.begin();
                    if (nf >= mid*r - pre[r]) ok = true;
                }
                if (ok) {
                    sup = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            chmax(ans, comp * full + sup * part);
        }
        for (int i=n-1; i>=0; i--) {
            if (a[i] + nf < t) break;
            nf -= (t-a[i]);
            comp++;
            ll lo = 0, hi = t-1, sup = 0;
            while (lo <= hi) {
                ll mid = (lo+hi)/2;
                auto it = lower_bound(a.begin(), a.begin()+i, mid);
                bool ok = false;
                if (it == a.begin()) ok = true;
                else {
                    int r = it - a.begin();
                    if (nf >= mid*r - pre[r]) ok = true;
                }
                if (ok) {
                    sup = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            if (i > 0)chmax(ans, comp*full + sup*part);
            else chmax(ans, comp*full);
        }
        return ans;        
    }
};