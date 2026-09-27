template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    int maxSubarray(vector<int>& a) {
        int n = a.size(), sz = 501;
        vvi idx(sz);
        for (int i=0; i<n; i++) {
            idx[a[i]].push_back(i);
        }
        vi b(n,n);
        for (int i=0; i<n; i++) {
            for (int x=1; x<sz; x++) {
                auto &vx = idx[x];
                auto it1 = upper_bound(vx.begin(), vx.end(), i);
                if (it1 != vx.end()) {
                    auto f = [&] (int y) {
                        if (x == y) {
                            auto it2 = next(it1);
                            if (it2 != vx.end()) {
                                chmin(b[i], *it2);
                            }
                        }
                        else if (1 <= y && y < sz) {
                            auto &vy = idx[y];
                            auto it2 = upper_bound(vy.begin(), vy.end(), i);
                            if (it2 != vy.end()) {
                                auto mx = max(*it1, *it2);
                                chmin(b[i], mx);
                            }
                        }
                    };
                    f(a[i]+x);
                    f(a[i]-x);
                }
            }
        }
        int ans = 1;
        for (int i=0; i<n; i++) {
            int tg = b[i];
            for (int j=b[i]-1; j>i; j--) {
                chmin(tg, b[j]);
            }
            chmax(ans, tg-i);
        }
        return ans;
    }
};