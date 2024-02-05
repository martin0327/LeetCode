using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

const ll inf = 2e18;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& pt) {
        vp a;
        for (auto xy : pt) {
            ll x = xy[0];
            ll y = -xy[1];
            a.push_back({x,y});
        }

        map<ll,ll> cnt;
        for (auto [x,y] : a) {
            cnt[x]++;
        }

        ll ans = 0;
        for (auto [x,c] : cnt) ans += c-1;

        sort(a.begin(), a.end());
        ll n = a.size();
        for (int i=0; i<n; i++) {
            auto [x1,y1] = a[i];
            ll lim = inf;
            if (i+1 < n && a[i+1].first == x1) lim = a[i+1].second;
            for (int j=i+1; j<n; j++) {
                auto [x2,y2] = a[j];
                if (x2 == x1) continue;
                if (y2 < y1) continue;
                if (y2 >= lim) continue;
                ans++;
                lim = min(lim, y2);
            }
        }
        return ans;

    }
};