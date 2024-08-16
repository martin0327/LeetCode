using ld = long double;
using ll = long long;
using pii = pair<ll,ll>;
using pdd = pair<ld,ld>;
using vi = vector<ll>;
using vp = vector<pii>;

class Solution {
public:
    vp a;
    ll n, r;

    ll sq (ll x) { return x*x; }
    ld sq (ld x) { return x*x; }

    pii mid(pii a, pii b) {
        auto [x1,y1] = a;
        auto [x2,y2] = b;
        return {(x1+x2)/2, (y1+y2)/2};
    }
    pii diff(pii a, pii b) {
        auto [x1,y1] = a;
        auto [x2,y2] = b;
        return {x2-x1, y2-y1};
    }
    pdd diff(pdd a, pdd b) {
        auto [x1,y1] = a;
        auto [x2,y2] = b;
        return {x2-x1,y2-y1};
    }
    vp ortho(pii a) {
        auto [x,y] = a;
        vp ret;
        ret.push_back({-y,x});
        ret.push_back({y,-x});
        return ret;
    }
    ld normsq(pii a) {
        auto [x,y] = a;
        return sq(x) + sq(y);
    }
    ld normsq(pdd a) {
        auto [x,y] = a;
        return sq(x) + sq(y);
    }

    ll f(pii p1, pii p2, pii o) {
        auto pm = mid(p1,p2);
        ld hsq = normsq(diff(pm,p2));
        ld lo = 0, hi = r, mul = -1;
        while (hi - lo > 1e-9) {
            ld mid = (lo+hi) / 2;
            ld bsq = normsq(make_pair(mid*o.first, mid*o.second));
            if (bsq + hsq <= r*r) {
                mul = mid;
                lo = mid;
            }
            else hi = mid;
        }
        pdd c = make_pair(pm.first + mul * o.first, pm.second + mul * o.second);

        ll ret = 2;
        for (auto p3 : a) {
            if (p3 == p1 || p3 == p2) continue;
            pdd t = {p3.first,p3.second};
            ld dsq = normsq(diff(c,t));
            if (dsq <= r*r+1e-6) ret++;
        }
        return ret;
    }

    int numPoints(vector<vector<int>>& darts, int _r) {
        n = darts.size();
        for (auto xy : darts) {
            ll x = 2*xy[0], y = 2*xy[1];
            a.push_back({x,y});
        }
        r = 2*_r;
        
        ll ans = 1;
        for (int i=0; i<n; i++) {
            pii p1 = a[i];
            for (int j=i+1; j<n; j++) {
                pii p2 = a[j];
                if (normsq(diff(p1,p2)) > sq(2*r)) continue;

                pii pm = mid(p1,p2);
                auto orth = ortho(diff(p1,pm));
                for (auto o : orth) {
                    ans = max(ans, f(p1,p2,o));
                }
            }
        }
        return ans;
        
    }
};