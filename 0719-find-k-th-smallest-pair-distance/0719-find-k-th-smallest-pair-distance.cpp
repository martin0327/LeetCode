using ll = long long;
using vi = vector<ll>;

struct fenwick {
    int n;
    vi a;
    fenwick(int n) {
        this->n = n;
        a = vi(n);
    }

    void add(int p, ll x) {
        p++;
        while (p <= n) {
            a[p-1] += x;
            p += p & -p;
        }
    }

    ll sum(int p) {
        ll res = 0;
        while (p) {
            res += a[p-1];
            p -= p & -p;
        }
        return res;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l);
    }
};

class Solution {
public:
int smallestDistancePair(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        ll mx = a.back();
        ll lo = 0, hi = mx, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            fenwick fen(mx+1);
            ll cnt = 0;
            for (auto x : a) {
                ll lim = max(0ll, x - mid);
                cnt += fen.sum(lim,x+1);
                fen.add(x,1);
            }
            if (cnt >= k) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};