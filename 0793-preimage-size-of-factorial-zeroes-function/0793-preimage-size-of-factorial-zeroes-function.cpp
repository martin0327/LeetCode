using ll = long long;
using vi = vector<ll>;
vi b;
class Solution {
public:
    int preimageSizeFZF(int k) {
        if (b.empty()) {
            b = {5};
            while (b.back() < 1e15) {
                b.push_back(b.back() * 5);
            }
        }
        auto f = [&] (ll x) {
            ll lo = 0 , hi = 1e12, ans = -1;
            while (lo <= hi) {
                ll mid = (lo+hi)/2;
                ll cnt = 0;
                for (auto z : b) {
                    cnt += 5*mid / z;
                }
                if (cnt <= x) {
                    ans = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            return ans;
        };
        auto ans = 5*(f(k) - f(k-1));
        return ans;
    }
};