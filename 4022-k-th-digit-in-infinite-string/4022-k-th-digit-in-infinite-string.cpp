using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    int kthDigit(long long k) {
        if (k <= 9) return k;
        k--;
        vi a = {9};
        for (int i=0; i<15; i++) {
            a.push_back(a.back() * 10ll);
        }
        ll n = a.size(), cum = 0, ans = -1;
        for (int i=0;i<n;i++) {
            ll x = a[i] * (i+1);
            if (k > x) k -= x;
            else {
                auto q = k / (10*(i+1));
                auto r = k % (10*(i+1));
                auto st = cum + 1 + q*10;
                string s;
                if ((st/10)%2 == 0) {
                    for (ll j = 0; j<10; j++) {
                        s += to_string(st+j);
                    }
                }
                else {
                    for (ll j = 9; j>=0; j--) {
                        s += to_string(st+j);
                    }
                }
                int sz = s.size();
                assert(r < sz);
                ans = s[r] - '0';
                break;
            }
            cum += a[i];
        }
        return ans;
    }
};