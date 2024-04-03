
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const ll mod = 1e9+7;

template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}

template<typename T>
vector<T> get_unique(vector<T> a) {
    asort(a);
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}


class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        vi a(nums.begin(), nums.end());
        ll n = a.size();
        sort(a.begin(), a.end());
        a.insert(a.begin(), -1e9);
        vi diffs;
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                diffs.push_back(abs(a[i]-a[j]));
            }
        }
        diffs = get_unique(diffs);
        ll ans = 0;
        for (auto d : diffs) {
            vvvi dp(n+1, vvi(k+1, vi(2)));
            dp[0][0][0] = 1;
            for (int i=0; i<n; i++) {
                for (int j=0; j<k; j++) {
                    for (int l=0; l<2; l++) {
                        if (dp[i][j][l] == 0) continue;
                        for (int ni=i+1; ni<=n; ni++) {
                            ll w = abs(a[i] - a[ni]);
                            if (w >= d) {
                                int nl = l | (w == d);
                                dp[ni][j+1][nl] += dp[i][j][l];
                                dp[ni][j+1][nl] %= mod;
                            }
                        }
                    }
                }
            }
            ll cnt = 0;
            for (int i=0; i<=n; i++) {
                cnt += dp[i][k][1];
                cnt %= mod;
            }
            // debug(d,cnt);
            ans += d * cnt;
            ans %= mod;
        }
        return ans;
    }
};