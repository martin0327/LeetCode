template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    long long maxPairStrength(vector<int>& aa) {
        vi a(aa.begin(), aa.end());
        int n = a.size();
        auto sq = [&] (ll x) { return x*x; };
        ll ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                ll t = (a[i]*a[j]) / sq(gcd(a[i],a[j]));
                chmax(ans, t);
            }
        }
        return ans;
    }
};